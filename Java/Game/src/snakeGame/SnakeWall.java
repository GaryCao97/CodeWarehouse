package snakeGame;

import java.util.ArrayList;

import javafx.animation.KeyFrame;
import javafx.animation.Timeline;
import javafx.scene.Group;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;
import javafx.util.Duration;

public class SnakeWall {
	static final double WIDTH = Snake.WIDTH, HEIGHT = Snake.HEIGHT;
	static ArrayList<Wall> walls = new ArrayList<Wall>();
	static ArrayList<Wall> endWall = new ArrayList<Wall>();
	static private Timeline endingAnimation;
	static Group parent;
	static void bindParent(Group p) {parent = p;}
	static void createEndWall() {
		endWall.clear();
		Wall w;
		for(int j = 1;j < (HEIGHT/Wall.SIZE - 1);j++) {
			for(int i = 1;i < (WIDTH/Wall.SIZE - 1);i++) {
				w = new Wall();
				endWall.add(w);
				w.setLayoutX(i * Wall.SIZE);
				w.setLayoutY(j * Wall.SIZE);
			}
		}
		endingAnimation = new Timeline(new KeyFrame(Duration.millis(10), e1 -> {
			if(endWall.size() != 0) {
				parent.getChildren().add(endWall.get(0));
				endWall.remove(0);
			}
			else endingAnimation.stop();
		}));
		endingAnimation.setCycleCount(Timeline.INDEFINITE);
		endingAnimation.play();
	}
	static void createBorderWall() {
		walls.clear();
		Wall w;
		for(int i = 0;i < WIDTH/Wall.SIZE;i++) {
			w = new Wall();
			walls.add(w);
			parent.getChildren().add(w);
			w.setLayoutX(i * Wall.SIZE);
			w.setLayoutY(0);
			w = new Wall();
			walls.add(w);
			parent.getChildren().add(w);
			w.setLayoutX(i * Wall.SIZE);
			w.setLayoutY(HEIGHT - Wall.SIZE);
		}
		for(int i = 1;i < (HEIGHT/Wall.SIZE) - 1;i++) {
			w = new Wall();
			walls.add(w);
			parent.getChildren().add(w);
			w.setLayoutY(i * Wall.SIZE);
			w.setLayoutX(0);
			w = new Wall();
			walls.add(w);
			parent.getChildren().add(w);
			w.setLayoutY(i * Wall.SIZE);
			w.setLayoutX(WIDTH - Wall.SIZE);
		}
	}
}

class Wall extends Pane {
	Rectangle rect;
	Position pos;
	static final double SIZE = SnakeNode.SIZE;
	public Wall() {
		pos = new Position(0,0);
		rect = new Rectangle(0,0,SIZE,SIZE);
		rect.setFill(Color.rgb(250, 200, 0));
		rect.setStroke(Color.BLACK);
		this.getChildren().add(rect);
		this.layoutXProperty().addListener(ov1 -> {
			pos.setX(this.getLayoutX());
		});
		this.layoutYProperty().addListener(ov1 -> {
			pos.setY(this.getLayoutY());
		});
	}
}