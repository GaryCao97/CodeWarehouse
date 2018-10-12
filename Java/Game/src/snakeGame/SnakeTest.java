package snakeGame;

import javafx.animation.FadeTransition;
import javafx.animation.KeyFrame;
import javafx.animation.Timeline;
import javafx.application.Application;
import javafx.beans.property.BooleanProperty;
import javafx.beans.property.SimpleBooleanProperty;
import javafx.scene.Cursor;
import javafx.scene.Scene;
import javafx.scene.input.KeyCode;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.Pane;
import javafx.scene.layout.StackPane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;
import javafx.scene.text.Text;
import javafx.stage.Stage;
import javafx.util.Duration;

public class SnakeTest extends Application {
	Snake snake = new Snake();
	SnakeStatus statusPane = new SnakeStatus();
	Pane gamePane = new Pane();
	BorderPane mainPane = new BorderPane();
	Scene gameScene = new Scene(mainPane);
	Position nowDirect = new Position(0,Snake.PER_STEP);
	Timeline snakeMove;
	Timeline foodCreate;
	double realRate;
	BooleanProperty gameOver = new SimpleBooleanProperty();
	public void start(Stage primaryStage) throws Exception {
		// TODO 自动生成的方法存根
		gameOver.set(false);
		mainPane.setCenter(gamePane);
		mainPane.setRight(statusPane);
		gamePane.setPrefSize(Snake.WIDTH, Snake.HEIGHT);
		gamePane.getChildren().add(snake);
		
		//键盘事件响应函数
		gameScene.setOnKeyPressed(kp1 -> {
			switch(kp1.getCode()) {
			case UP:
				if(nowDirect.notEqual(new Position(0,Snake.PER_STEP))) {
					nowDirect = new Position(0,-Snake.PER_STEP);
					snake.addDirect(nowDirect);
				}
				break;
			case DOWN:
				if(nowDirect.notEqual(new Position(0,-Snake.PER_STEP))) {
					nowDirect = new Position(0,Snake.PER_STEP);
					snake.addDirect(nowDirect);
				}
				break;
			case LEFT:
				if(nowDirect.notEqual(new Position(Snake.PER_STEP,0))) {
					nowDirect = new Position(-Snake.PER_STEP,0);
					snake.addDirect(nowDirect);
				}
				break;
			case RIGHT:
				if(nowDirect.notEqual(new Position(-Snake.PER_STEP,0))) {
					nowDirect = new Position(Snake.PER_STEP,0);
					snake.addDirect(nowDirect);
				}
				break;
			case SPACE:
				snakeMove.setRate(realRate * 5);
				break;
			default:
				break;
			}
		});
		gameScene.setOnKeyReleased(kp2 -> {
			if(kp2.getCode() == KeyCode.SPACE) {
				snakeMove.setRate(realRate);
			}
		});
		
		//动画：蛇的移动
		snakeMove = new Timeline(new KeyFrame(Duration.millis(150), e1 -> {
			snake.moveSnake();
			snake.snakeEatFood();
			if(snake.selfHit() || snake.wallsHit()) {
				gameOver.set(true);
			}
		}));
		snakeMove.setCycleCount(Timeline.INDEFINITE);
		snakeMove.play();
		realRate = snakeMove.getRate();
		//System.out.println(realRate);
		//snakeMove.stop();
		
		//动画：食物和墙的生成
		SnakeFood.bindParent(snake);
		SnakeWall.bindParent(snake);
		SnakeWall.createBorderWall();
		foodCreate = new Timeline(new KeyFrame(Duration.millis(1000), e1 -> {
			SnakeFood.createFood();
		}));
		foodCreate.setCycleCount(Timeline.INDEFINITE);
		foodCreate.play();
		
		//分数响应
		snake.score.addListener(l1 -> {
			statusPane.setScore(snake.score.get());
		});
		
		//游戏结束响应
		gameOver.addListener(l2 -> {
			if(gameOver.get()) {
				snakeMove.stop();
				foodCreate.stop();
				statusPane.stop();
				//gamePane.getChildren().clear();
				SnakeWall.createEndWall();
				gameOverAnimation();
			}
		});
		
		primaryStage.setScene(gameScene);
		primaryStage.setTitle("贪吃蛇游戏");
		primaryStage.show();
	}
	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		launch(args);
	}
	private void gameOverAnimation() {
		FadeTransition endAnime;
		StackPane endPane = new StackPane();
		Rectangle background = new Rectangle(0,0,Snake.WIDTH/2,Snake.HEIGHT/4);
		background.setFill(Color.BROWN);
		Text endText = new Text("游戏结束");
		endText.setFont(Font.font("Times", FontWeight.BOLD, 24));
		endPane.getChildren().addAll(background,endText);
		endPane.setPrefSize(0, 0);
		gamePane.getChildren().add(endPane);
		endPane.setStyle(String.format("-fx-padding: %g %g %g %g;",(Snake.HEIGHT*3/8),(Snake.WIDTH/4),(Snake.HEIGHT*3/8),(Snake.WIDTH/4)));
		endPane.setOpacity(0);
		endAnime = new FadeTransition(Duration.millis(2000), endPane);
		endAnime.setFromValue(0);
		endAnime.setToValue(1);
		endAnime.setCycleCount(1);
		endAnime.play();
		background.setCursor(Cursor.HAND);
		endPane.setOnMouseClicked(mc -> {
			gameOver.set(false);
			gamePane.getChildren().remove(endPane);
			snake.restart();
			SnakeFood.restart();
			SnakeWall.createBorderWall();
			snakeMove.play();
			foodCreate.play();
			statusPane.restart();
		});
	}
}
