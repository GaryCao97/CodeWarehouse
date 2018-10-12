package sy6;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

import javafx.geometry.Pos;
import javafx.scene.control.Label;
import javafx.scene.control.ScrollPane;
import javafx.scene.control.TextArea;
import javafx.scene.layout.BorderPane;
import javafx.scene.paint.Color;

public class LogPane extends BorderPane {
	private File file;
	Label lbDate = new Label();
	TextArea taLog = new TextArea();
	ScrollPane spLog = new ScrollPane(taLog);
	
	public LogPane() {
		lbDate.setAlignment(Pos.CENTER);
		lbDate.setStyle("-fx-background-color:#eeaaaa;");
		lbDate.setPrefWidth(300);
		lbDate.setPrefHeight(30);
		lbDate.setTextFill(Color.BLACK);
		
		taLog.setWrapText(true);
		
		spLog.setStyle("-fx-padding:0 0 0 0;");
		
		this.setTop(lbDate);
		this.setCenter(spLog);
		BorderPane.setAlignment(lbDate, Pos.CENTER);
		BorderPane.setAlignment(spLog, Pos.CENTER);
	}
	public void updateDate(int year, int month, int date) {
		file = new File(String.format("E:\\Java\\log\\%d%02d%02d.txt", year, month, date));
		lbDate.setText(String.format("%dƒÍ%d‘¬%d»’", year, month, date));
	}
	public void saveLog() throws FileNotFoundException {
		PrintWriter output = new PrintWriter(file);
		output.println(taLog.getText());
		output.close();
	}
	public void delLog() {
		taLog.setText("");
	}
	public void openLog() throws FileNotFoundException {
		if(file.exists()) {
			Scanner input = new Scanner(file);
			String logStr = new String();
			while(input.hasNextLine()) {
				logStr = logStr + input.nextLine() + '\n';
			}
			taLog.setText(logStr);
			input.close();
		}
		else {
			taLog.setText("");
		}
	}
}
