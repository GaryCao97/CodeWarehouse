package snakeGame;

import javafx.animation.KeyFrame;
import javafx.animation.Timeline;
import javafx.scene.Group;
import javafx.scene.layout.Pane;
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;
import javafx.scene.text.Text;
import javafx.util.Duration;

public class SnakeStatus extends Pane {
	static final double WIDTH = 200, HEIGHT = Snake.HEIGHT;
	private Group status;
	private Text tScore,tTime;
	private int hh,mm,ss;
	private Timeline time;
	public SnakeStatus() {
		hh = mm = ss = 0;
		this.setPrefSize(WIDTH, HEIGHT);
		status = new Group();
		tScore = new Text();
		tScore.setFont(Font.font("Times", FontWeight.BOLD, 30));
		tTime = new Text();
		tTime.setFont(Font.font("Times", FontWeight.BOLD, 30));
		this.getChildren().add(status);
		this.getChildren().add(tScore);
		this.getChildren().add(tTime);
		tScore.setLayoutX(WIDTH / 2 - 40);
		tScore.setLayoutY(HEIGHT / 3);
		tTime.setLayoutX(WIDTH / 2 - 40);
		tTime.setLayoutY(HEIGHT * 2 / 3);
		tTime.setText(String.format("%02d:%02d:%02d", hh,mm,ss));
		time = new Timeline(new KeyFrame(Duration.millis(1000), e1 -> {
			ss++;
			if(ss >= 60) {
				ss = 0;
				mm++;
			}
			if(mm >= 60) {
				mm = 0;
				hh++;
			}
			tTime.setText(String.format("%02d:%02d:%02d", hh,mm,ss));
		}));
		time.setCycleCount(Timeline.INDEFINITE);
		time.play();
		setScore(0);
	}
	public void restart() {
		hh = mm = ss = 0;
		time.play();
	}
	public void setScore(int score) {
		tScore.setText("·ÖÊý:" + score);
	}
	public void stop() {
		time.stop();
	}
}
