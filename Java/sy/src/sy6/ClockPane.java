package sy6;

import java.util.Calendar;
import java.util.GregorianCalendar;

import javafx.animation.KeyFrame;
import javafx.animation.Timeline;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import javafx.scene.shape.Rectangle;
import javafx.scene.text.Text;
import javafx.util.Duration;

public class ClockPane extends Pane {
	private int hour, minute, second;
	private double width = 300, height = 300;
	public ClockPane() {
		setCurrentTime();
		paintClock();
		setStyle("-fx-background-color:#aaaaaa;");

		Timeline animation = new Timeline(new KeyFrame(Duration.millis(1000), e -> {
			moveNext();
		}));
		animation.setCycleCount(Timeline.INDEFINITE);
		animation.play();
	}
	public ClockPane(int hour, int minute, int second) {
		this.hour = hour;
		this.minute = minute;
		this.second = second;
		paintClock();
		setStyle("-fx-background-color:#aaaaaa;");

		Timeline animation = new Timeline(new KeyFrame(Duration.millis(1000), e -> {
			moveNext();
		}));
		animation.setCycleCount(Timeline.INDEFINITE);
		animation.play();
	}
	public int getHour() {return hour;}
	public int getMinute() {return minute;}
	public int getSecond() {return second;}
	public double getW() {return width;}
	public double getH() {return height;}
	public void setHour(int hour) {
		this.hour = hour;
		paintClock();
	}
	public void setMinute(int minute) {
		this.minute = minute;
		paintClock();
	}
	public void setSecond(int second) {
		this.second = second;
		paintClock();
	}
	public void setW(double width) {
		this.width = width;
		paintClock();
	}
	public void setH(double height) {
		this.height = height;
		paintClock();
	}
	public void setCurrentTime() {
		Calendar calendar = new GregorianCalendar();
		this.hour = calendar.get(Calendar.HOUR_OF_DAY);
		this.minute = calendar.get(Calendar.MINUTE);
		this.second = calendar.get(Calendar.SECOND);
	}
	public void moveNext() {
		second += 1;
		if(second == 60) {
			second = 0;
			minute += 1;
		}
		if(minute == 60) {
			minute = 0;
			hour += 1;
		}
		if(hour == 24) {
			hour = 0;
		}
		paintClock();
	}
	public void paintClock() {
		double clockRadius = Math.min(width, height) * 0.8 * 0.5;
		double centerX = width / 2.0, centerY = height / 2.0;
		Circle[] circle = new Circle[61];
		Text[] text = new Text[12];
		for(int i = 0;i < 60; i++) {
			double x = centerX + clockRadius * Math.cos(2 * Math.PI * i / 60);
			double y = centerY - clockRadius * Math.sin(2 * Math.PI * i / 60);
			double r = 1;
			Color color = Color.BLACK;
			if(i % 15 == 0) {
				r = 7;
				color = Color.ORANGE;
			}
			else if(i % 5 == 0) {
				r = 4;
				color = Color.ORANGE;
			}
			circle[i] = new Circle(x, y, r);
			circle[i].setFill(color);
			
		}
		circle[60] = new Circle(centerX, centerY, 10);
		circle[60].setFill(Color.BLACK);
		
		for(int i = 0; i < 12; i++) {
			text[i] = new Text(centerX - 5 + (clockRadius + 20) * Math.sin((i+1) * 2 * Math.PI / 12.0), 
					centerY + 5 - (clockRadius + 20) * Math.cos((i+1) * 2 * Math.PI / 12.0),
					(i + 1) + "");
		}
		
		double secondL = clockRadius * 1.0;
		double secondX = centerX + 0.5 * secondL * Math.sin(second * 2 * Math.PI / 60.0);
		double secondY = centerY - 0.5 * secondL * Math.cos(second * 2 * Math.PI / 60.0);
		double minuteL = clockRadius * 0.85;
		double minuteX = centerX + 0.5 * minuteL * Math.sin((minute + second / 60.0) * 2 * Math.PI / 60.0);
		double minuteY = centerY - 0.5 * minuteL * Math.cos((minute + second / 60.0) * 2 * Math.PI / 60.0);
		double hourL = clockRadius * 0.7;
		double hourX = centerX + 0.5 * hourL * Math.sin((hour % 12 + (minute + second / 60.0) / 60.0) * 2 * Math.PI / 12.0);
		double hourY = centerY - 0.5 * hourL * Math.cos((hour % 12 + (minute + second / 60.0) / 60.0) * 2 * Math.PI / 12.0);
		Rectangle sRect = new Rectangle(secondX - 0.5 * secondL, secondY - 0.5, secondL, 1);
		Rectangle mRect = new Rectangle(minuteX - 0.5 * minuteL, minuteY - 1, minuteL, 2);
		Rectangle hRect = new Rectangle(hourX - 0.5 * hourL, hourY - 2, hourL, 4);
		sRect.setFill(Color.RED);
		mRect.setFill(Color.BLUE);
		hRect.setFill(Color.ORANGE);
		sRect.setRotate(- 90 + second * 360 / 60.0);
		mRect.setRotate(- 90 + (minute + second / 60.0) * 360 / 60.0);
		hRect.setRotate(- 90 + (hour % 12 + (minute + second / 60.0) / 60.0) * 360 / 12.0);

		getChildren().clear();
		getChildren().addAll(circle);
		getChildren().addAll(text);
		getChildren().addAll(sRect, mRect, hRect);
	}
}
