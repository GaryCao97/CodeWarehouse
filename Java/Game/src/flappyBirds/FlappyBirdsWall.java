package flappyBirds;

import java.util.ArrayList;

import javafx.animation.KeyFrame;
import javafx.animation.Timeline;
import javafx.scene.Group;
import javafx.scene.layout.Pane;
import javafx.scene.shape.Rectangle;
import javafx.util.Duration;

public class FlappyBirdsWall {
	static final double WIDTH = 400,HEIGHT = 400;
	static ArrayList<Walls> walls = new ArrayList<Walls>();
	static Timeline wallsAnime;
	static Group parent;
	static void bindParent(Group p) {
		parent = p;
	}
	static void createWalls() {
		double h = getRandom(FlappyBirds.SIZE,HEIGHT - FlappyBirds.SIZE * 6);
		if(walls.size()!=0) {
			do {
				h = walls.get(walls.size()-1).getAboveHeight() + getRandom(-FlappyBirds.SIZE * 3,FlappyBirds.SIZE * 3);
			}while(h <= 0);
		}
		Walls w = new Walls(h,HEIGHT - h - FlappyBirds.SIZE * 5);
		walls.add(w);
		parent.getChildren().add(w);
		w.setLayoutX(WIDTH);
		w.layoutXProperty().addListener(l -> {
			if(w.getLayoutX() < (WIDTH/2 - Walls.WALLS_WIDTH - FlappyBirds.SIZE/2))
				walls.remove(w);
			if(w.getLayoutX() < (-Walls.WALLS_WIDTH)) {
				//walls.remove(w);
				parent.getChildren().remove(w);
			}
		});
	}
	static void wallsMove() {
		wallsAnime = new Timeline(new KeyFrame(Duration.millis(30), e1 -> {
			for(int i = 0;i < parent.getChildren().size();i++) {
				if(parent.getChildren().get(i).toString().startsWith("Walls")) {
					parent.getChildren().get(i).setLayoutX(parent.getChildren().get(i).getLayoutX() - 1);
				}
			}
			if(walls.get(walls.size()-1).getLayoutX() < (WIDTH - Walls.WALLS_WIDTH * 3.5)) {
				createWalls();
			}
		}));
		wallsAnime.setCycleCount(Timeline.INDEFINITE);
		wallsAnime.play();
	}
	static void stop() {
		wallsAnime.stop();
	}
	static double getRandom(double left, double right) {
		return (Math.random() * (right - left) + left);
	}
}

class Walls extends Pane{
	static final double WALLS_WIDTH = FlappyBirds.SIZE * 1.2;
	private Rectangle aboveWall;
	private Rectangle belowWall;
	private Group walls;
	public Walls(double aboveHeight, double belowHeight) {
		this.setPrefSize(WALLS_WIDTH, FlappyBirdsWall.HEIGHT);
		walls = new Group();
		aboveWall = new Rectangle(0,0,WALLS_WIDTH,aboveHeight);
		belowWall = new Rectangle(0,0,WALLS_WIDTH,belowHeight);
		walls.getChildren().add(aboveWall);
		aboveWall.setLayoutX(0);
		aboveWall.setLayoutY(0);
		walls.getChildren().add(belowWall);
		belowWall.setLayoutX(0);
		belowWall.setLayoutY(FlappyBirdsWall.HEIGHT - belowHeight);
		this.getChildren().add(walls);
	}
	public double getAboveHeight() {
		return aboveWall.getHeight();
	}
	public double getBelowHeight() {
		return belowWall.getLayoutY();
	}
}