package flappyBirds;

import javafx.animation.KeyFrame;
import javafx.animation.Timeline;
import javafx.scene.Group;
import javafx.scene.shape.Circle;
import javafx.util.Duration;

public class FlappyBirds {
	static final double SIZE = 40;
	private Circle bird;
	private Group parent;
	//private double speedX;
	private double speedY;
	private static final double gravity = SIZE / 100;
	private Timeline birdAnime;
	//private ImageView bird;
	public FlappyBirds(Group parent) {
		//bird = new ImageView(new Image("file:/birds.jpg"));
		bird = new Circle(SIZE / 2,SIZE / 2,SIZE / 2);
		this.parent = parent;
		this.parent.getChildren().add(bird);
		bird.setLayoutX(0.5 * FlappyBirdsWall.WIDTH - SIZE / 2);
		bird.setLayoutY(0.5 * FlappyBirdsWall.HEIGHT - SIZE / 2);
		speedY = 0;
		birdAnime = new Timeline(new KeyFrame(Duration.millis(50), e1 -> {
			speedY = speedY + gravity;
			bird.setLayoutY(bird.getLayoutY() + speedY);
			if(hitWall() || outOfWindow()){
				birdAnime.stop();
				FlappyBirdsWall.stop();
			}
		}));
		birdAnime.setCycleCount(Timeline.INDEFINITE);
		birdAnime.play();
	}
	public void birdJump() {
		speedY = -5;
	}
	boolean outOfWindow() {
		if(bird.getLayoutY() > (FlappyBirdsWall.HEIGHT-SIZE))return true;
		return false;
	}
	boolean hitWall() {
		if(bird.getLayoutX() <= (FlappyBirdsWall.walls.get(0).getLayoutX() - SIZE))return false;
		if(bird.getLayoutX() >= (FlappyBirdsWall.walls.get(0).getLayoutX() + Walls.WALLS_WIDTH))return false;
		if(bird.getLayoutX() < (FlappyBirdsWall.walls.get(0).getLayoutX())) {
			if(bird.getLayoutY() <= (FlappyBirdsWall.walls.get(0).getAboveHeight() - SIZE) || 
					bird.getLayoutY() >= (FlappyBirdsWall.walls.get(0).getBelowHeight()))
				return true;
			else {
				double x = bird.getCenterX() + bird.getLayoutX(),y = bird.getCenterY() + bird.getLayoutY();
				double x1,x2,y1,y2;
				x1 = x2 = FlappyBirdsWall.walls.get(0).getLayoutX();
				y1 = FlappyBirdsWall.walls.get(0).getAboveHeight();
				y2 = y1 + 5 * SIZE;
				double disU = Math.sqrt(Math.pow(x - x1, 2) + Math.pow(y - y1, 2)),
						disD = Math.sqrt(Math.pow(x - x2, 2) + Math.pow(y - y2, 2));
				if(disU < (SIZE/2) || disD < (SIZE/2))
					return true;
			}
		}
		else{
			if(bird.getLayoutY() < FlappyBirdsWall.walls.get(0).getAboveHeight() || 
					bird.getLayoutY() > (FlappyBirdsWall.walls.get(0).getBelowHeight() - SIZE))
				return true;
			else {
				double x = bird.getCenterX() + bird.getLayoutX(),y = bird.getCenterY() + bird.getLayoutY();
				double x1,x2,y1,y2;
				x1 = x2 = FlappyBirdsWall.walls.get(0).getLayoutX() + Walls.WALLS_WIDTH;
				y1 = FlappyBirdsWall.walls.get(0).getAboveHeight();
				y2 = y1 + 5 * SIZE;
				double disU = Math.sqrt(Math.pow(x - x1, 2) + Math.pow(y - y1, 2)),
						disD = Math.sqrt(Math.pow(x - x2, 2) + Math.pow(y - y2, 2));
				if(disU < (SIZE/2) || disD < (SIZE/2))
					return true;
			}
		}
		return false;
	}

}
