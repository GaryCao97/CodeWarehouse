package planesWar;

import java.util.ArrayList;

import javafx.animation.KeyFrame;
import javafx.animation.Timeline;
import javafx.application.Application;
import javafx.beans.property.SimpleBooleanProperty;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Ellipse;
import javafx.scene.shape.Polygon;
import javafx.stage.Stage;
import javafx.util.Duration;

public class PlanesWarGame1 extends Application {
	public void start(Stage primaryStage) throws Exception {
		// TODO 自动生成的方法存根
		primaryStage.setTitle("飞机大战游戏");
		primaryStage.setScene(new GamingPane());
		primaryStage.show();
	}
	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		launch(args);
	}
}

class GamingPane extends Scene {
	private Group gamePane = new Group();
	ArrayList<Plane> otherPlane;
	Plane myPlane;
	SimpleBooleanProperty isEnd;
	
	private final static double WIDTH = 800, HEIGHT = 800, PER_STEP = 10;
	
	public GamingPane() {
		super(new Pane(),WIDTH,HEIGHT);
		isEnd = new SimpleBooleanProperty();
		isEnd.setValue(false);
		this.setRoot(gamePane);
		myPlane = new Plane();
		otherPlane = new ArrayList<Plane>();
		gamePane.getChildren().add(myPlane);
		myPlane.setLayoutX(WIDTH / 2 - myPlane.getWidth() / 2);
		myPlane.setLayoutY(HEIGHT - myPlane.HEIGHT - 10);
		Timeline animation1 = new Timeline(new KeyFrame(Duration.millis(1000), e -> {
			Plane op = new Plane(false);
			otherPlane.add(op);
			gamePane.getChildren().add(op);
			op.setLayoutX(getRandom(0,WIDTH));
			op.setLayoutY(0);
			op.layoutYProperty().addListener(ov -> {
				if(op.getLayoutY() > HEIGHT) {
					otherPlane.remove(op);
					gamePane.getChildren().remove(op);
				}
			});
		}));
		animation1.setCycleCount(Timeline.INDEFINITE);
		animation1.play();
		Timeline animation3 = new Timeline(new KeyFrame(Duration.millis(100), e -> {
			myPlane.sendBullet();
			gamePane.getChildren().add(myPlane.getBullet().get(myPlane.getBullet().size()-1));
			myPlane.getBullet().get(myPlane.getBullet().size()-1).centerYProperty().addListener(ov -> {
				if(myPlane.getBullet().get(myPlane.getBullet().size()-1).getCenterY() < 0) {
					gamePane.getChildren().remove(myPlane.getBullet().get(myPlane.getBullet().size()-1));
					myPlane.getBullet().remove(myPlane.getBullet().size()-1);
				}
			});
		}));
		Timeline animation2 = new Timeline(new KeyFrame(Duration.millis(50), e -> {
			for(int i = 0;i < otherPlane.size();i++) {
				otherPlane.get(i).setLayoutY(otherPlane.get(i).getLayoutY() + PER_STEP);
			}
			for(int i = 0;i < otherPlane.size();i++) {
				for(int j = 0;j < myPlane.getBullet().size(); j++) {
					if(isHash(otherPlane.get(i),myPlane.getBullet().get(j))) {
						gamePane.getChildren().remove(otherPlane.get(i));
						gamePane.getChildren().remove(myPlane.getBullet().get(j));
						otherPlane.remove(i);
						myPlane.getBullet().remove(j);
						i--;
						break;
					}
				}
			}
			for(int i = 0;i < otherPlane.size();i++) {
				if(isHash(otherPlane.get(i),myPlane)) {
					gamePane.getChildren().remove(myPlane);
					gamePane.getChildren().remove(otherPlane.get(i));
					isEnd.setValue(true);
				}
			}
		}));
		animation2.setCycleCount(Timeline.INDEFINITE);
		animation2.play();
		animation3.setCycleCount(Timeline.INDEFINITE);
		animation3.play();
		this.setOnKeyPressed(ev -> {
			switch(ev.getCode()) {
			case UP:
				myPlane.moveUp();
				break;
			case DOWN:
				myPlane.moveDown();
				break;
			case LEFT:
				myPlane.moveLeft();
				break;
			case RIGHT:
				myPlane.moveRight();
				break;
			default:
				break;
			}
		});
		isEnd.addListener(lv -> {
			if(isEnd.get()) {
				gamePane.getChildren().clear();
				otherPlane.clear();
				myPlane.getBullet().clear();
				for(int j = 0;j < myPlane.getBulletsAnime().size(); j++) 
					myPlane.getBulletsAnime().get(j).stop();
				animation1.stop();
				animation2.stop();
				animation3.stop();
			}
		});
	}

	private boolean isHash(Plane p, Bullet b) {
		double pX = p.getLayoutX() + p.getWidth() / 2;
		double pY = p.getLayoutY() + p.getHeight() / 2;
		double bX = b.getCenterX(), bY = b.getCenterY();
		double dis = Math.sqrt(Math.pow(bX - pX, 2) + Math.pow(bY - pY, 2));
		return dis < 10;
	}
	private boolean isHash(Plane p1, Plane p2) {
		double p1X = p1.getLayoutX() + p1.getWidth() / 2;
		double p1Y = p1.getLayoutY() + p1.getHeight() / 2;
		double p2X = p2.getLayoutX() + p2.getWidth() / 2;
		double p2Y = p2.getLayoutY() + p2.getHeight() / 2;
		double dis = Math.sqrt(Math.pow(p1X - p2X, 2) + Math.pow(p1Y - p2Y, 2));
		return dis < 25;
	}
	private double getRandom(double left, double right) {
		return (Math.random() * (right - left + 1) + left);
	}
}

class Plane extends Pane {
	private Polygon plane;
	private boolean isMyPlane;//
	private ArrayList<Bullet> bullets;
	private ArrayList<Timeline> bulletsAnime;
	
	final double WIDTH = 20, HEIGHT = 50, PER_STEP = 10, PER_STEP_BULLET = 10;
	private final double[][] myPlane = {{WIDTH / 2,0},{0,HEIGHT},{WIDTH / 2,HEIGHT * 3 / 4},{WIDTH,HEIGHT}};
	private final double[][] otherPlane = {{WIDTH / 2,HEIGHT},{0,0},{WIDTH / 2,HEIGHT * 1 / 4},{WIDTH,0}};
	private final Color myColor = Color.rgb(160, 40, 200);
	private final Color otherColor = Color.rgb(200, 60, 60);
	
	public Plane() {
		this(true);
	}
	public Plane(boolean isMyPlane) {
		bullets = new ArrayList<Bullet>();
		bulletsAnime = new ArrayList<Timeline>();
		this.setPrefSize(WIDTH, HEIGHT);
		this.isMyPlane = isMyPlane;
		plane = new Polygon();
		this.getChildren().add(plane);
		double[][] planeArr = this.isMyPlane? myPlane : otherPlane;
		Color color = this.isMyPlane? myColor : otherColor;
		drawPlane(planeArr, color);
	}
	public void moveUp() {
		this.setLayoutY(this.getLayoutY() - PER_STEP);
	}
	public void moveDown() {
		this.setLayoutY(this.getLayoutY() + PER_STEP);
	}
	public void moveLeft() {
		this.setLayoutX(this.getLayoutX() - PER_STEP);
	}
	public void moveRight() {
		this.setLayoutX(this.getLayoutX() + PER_STEP);
	}
	public void sendBullet() {
		if(isMyPlane) {
			Bullet b = new Bullet();
			bullets.add(b);
			b.setCenterX(this.getLayoutX() + this.WIDTH / 2);
			b.setCenterY(this.getLayoutY() - 10);
			Timeline bulletAnima = new Timeline(new KeyFrame(Duration.millis(20), e -> {
				b.setCenterY(b.getCenterY() - PER_STEP_BULLET);
			}));
			bulletsAnime.add(bulletAnima);
			bulletAnima.setCycleCount(Timeline.INDEFINITE);
			bulletAnima.play();
		}
		else {
			
		}
	}
	public ArrayList<Bullet> getBullet() {
		return bullets;
	}
	public ArrayList<Timeline> getBulletsAnime() {
		return bulletsAnime;
	}
	private void drawPlane(double[][] planeArr,Color color) {
		plane.setFill(color);
		plane.setStroke(Color.rgb(0, 0, 0));
		for(int i = 0;i < planeArr.length;i++) 
			for(int j = 0;j < planeArr[i].length;j++) 
				plane.getPoints().add(planeArr[i][j]);
	}
}
class Bullet extends Ellipse {
	double bulletSize;
	public Bullet() {
		this(5);
	}
	public Bullet(double bulletSize) {
		this.bulletSize = bulletSize;
		this.setRadiusX(this.bulletSize);
		this.setRadiusY(this.bulletSize);
	}
}
