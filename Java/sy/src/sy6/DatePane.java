package sy6;

import java.util.Calendar;
import java.util.GregorianCalendar;

import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.control.Label;
import javafx.scene.control.Labeled;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.Pane;
import javafx.scene.layout.StackPane;
import javafx.scene.paint.Color;

public class DatePane extends Pane {
	private double w = 400, h = 200;
	private int year, month, date;
	private int monthDay;
	private int emptyNum;
	private GridPane thisPane = new GridPane();
	private Cell[] tHead = new Cell[7];
	private Cell[] tBody = new Cell[6 * 7];
	
	public DatePane() {
		for(int i = 0;i < 7;i++) 
			tHead[i] = new Cell();
		for(int i = 0;i < 6*7;i++) 
			tBody[i] = new Cell();
		thisPane.setAlignment(Pos.CENTER);
		thisPane.setVgap(0);
		thisPane.setHgap(0);
		thisPane.setPadding(new Insets(0,0,0,0));
		setCurrentMonth();
	}

	public int getYear() {return year;}
	public int getMonth() {return month;}
	public int getDate() {return date;}
	public double getW() {return w;}
	public double getH() {return h;}
	public void setYear(int year) {
		this.year = year;
		paintTBody();
	}
	public void setMonth(int month) {
		if(month > 12)month = 12;
		if(month < 1)month = 1;
		this.month = month;
		switch(month) {
		case 4:
		case 6:
		case 9:
		case 11:
			monthDay = 30;
			break;
		case 2:
			monthDay = ((year % 400 == 0) || ((year % 100 != 0) && (year % 4 == 0))) ? 29 : 28;
			break;
		default:
			monthDay = 31;
			break;
		}
		paintTBody();
	}
	public void setDate(int date) {
		if(date > monthDay)date = monthDay;
		if(date < 1)date = 1;
		this.date = date;
		paintTBody();
	}
	public void setW(double width) {
		this.w = width;
		paintTHead();
		paintTBody();
	}
	public void setH(double height) {
		this.h = height;
		paintTHead();
		paintTBody();
	}
	
	public void setCurrentMonth() {
		Calendar calendar = new GregorianCalendar();
		year = calendar.get(Calendar.YEAR);
		month = calendar.get(Calendar.MONTH) + 1;
		switch(month) {
		case 4:
		case 6:
		case 9:
		case 11:
			monthDay = 30;
			break;
		case 2:
			monthDay = ((year % 400 == 0) || ((year % 100 != 0) && (year % 4 == 0))) ? 29 : 28;
			break;
		default:
			monthDay = 31;
			break;
		}
		date = calendar.get(Calendar.DAY_OF_MONTH);
		paintTHead();
		paintTBody();
	}
	public void lastYear() {
		year--;
		paintTBody();
	}
	public void nextYear() {
		year++;
		paintTBody();
	}
	public void lastMonth() {
		month--;
		if(month == 0) {
			month = 12;
			year--;
		}
		paintTBody();
	}
	public void nextMonth() {
		month++;
		if(month == 13) {
			month = 1;
			year++;
		}
		paintTBody();
	}
	
	public void paintTHead() {
		String[] dateStr = {"SUN日","MON一","TUE二","WED三","THU四","FRI五","SAT六"};
		for(int i = 0;i < 7;i++) {
			Label text = new Label(dateStr[i]);
			text.setPrefWidth(w / 7.0);
			text.setPrefHeight(h / 7.0);
			text.setAlignment(Pos.CENTER);
			text.setStyle("-fx-background-color:#cccccc; -fx-border-color:black;");
			if(i == 0)text.setTextFill(Color.RED);
			else if(i == 6)text.setTextFill(Color.BLUE);
			else text.setTextFill(Color.BLACK);
			tHead[i].getChildren().clear();
			tHead[i].getChildren().add(text);
			thisPane.add(tHead[i], i, 0);
		}
		Calendar calendarTmp = new GregorianCalendar();
		calendarTmp.set(year, month - 1, 1);
		emptyNum = calendarTmp.get(Calendar.DAY_OF_WEEK) - 1;
		for(int i = 0;i < 6*7;i++) {
			Label text;
			if(i >= emptyNum && i < emptyNum + monthDay) {
				text = new Label((i - emptyNum + 1) + "");
			}
			else {
				text = new Label("");
			}
			text.setPrefWidth(w / 7.0);
			text.setPrefHeight(h / 7.0);
			text.setAlignment(Pos.CENTER);
			if((i - emptyNum + 1) == date)text.setStyle("-fx-background-color:orange; -fx-border-color:blue;");
			else text.setStyle("-fx-background-color:#ffffff; -fx-border-color:blue;");
			tBody[i].getChildren().clear();
			tBody[i].getChildren().add(text);
			thisPane.add(tBody[i], i % 7, (i / 7) + 1);
		}
		getChildren().clear();
		getChildren().add(thisPane);
	}
	public void paintTBody() {
		Calendar calendarTmp = new GregorianCalendar();
		calendarTmp.set(year, month - 1, 1);
		emptyNum = calendarTmp.get(Calendar.DAY_OF_WEEK) - 1;
		for(int i = 0;i < 6*7;i++) {
			Label text;
			if(i >= emptyNum && i < emptyNum + monthDay) {
				text = new Label((i - emptyNum + 1) + "");
			}
			else {
				text = new Label("");
			}
			text.setPrefWidth(w / 7.0);
			text.setPrefHeight(h / 7.0);
			text.setAlignment(Pos.CENTER);
			text.setStyle("-fx-border-color:blue;");
			if((i - emptyNum + 1) == date)tBody[i].setStyle("-fx-background-color:orange;");
			else tBody[i].setStyle("-fx-background-color:#ffffff;");
			tBody[i].getChildren().clear();
			tBody[i].getChildren().add(text);
		}
	}
	class Cell extends StackPane {
		public Cell() {
			this.setOnMouseClicked(e -> {
				setDate(Integer.parseInt(((Labeled) this.getChildren().get(0)).getText()));
			});
		}
	}
}
