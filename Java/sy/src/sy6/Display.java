package sy6;
import java.io.FileNotFoundException;

import javafx.application.Application;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;
import sy6.ClockPane;
import sy6.DatePane;
import sy6.LogPane;

public class Display extends Application {
	private ClockPane clock = new ClockPane();
	private DatePane date = new DatePane();
	public static void main(String[] args) {
		Application.launch(args);
	}
	public void start(Stage primaryStage) {
		VBox paneLeft = new VBox(5);
		paneLeft.getChildren().add(date);
		paneLeft.getChildren().add(clock);
		clock.setW(date.getW());
		
		HBox hBoxTop = new HBox(10);
		hBoxTop.setAlignment(Pos.CENTER);
		hBoxTop.setStyle("-fx-padding:10 10 10 10;");
		Button btnLastYear = new Button("上年"),
				btnNextYear = new Button("下年"),
				btnLastMonth = new Button("上月"),
				btnNextMonth = new Button("下月");
		TextField tfYear = new TextField(date.getYear() + ""),
				tfMonth = new TextField(date.getMonth() + "");
		tfYear.setPrefWidth(100);
		tfMonth.setPrefWidth(100);
		hBoxTop.getChildren().addAll(btnLastYear, tfYear, btnNextYear, btnLastMonth, tfMonth, btnNextMonth);
		
		LogPane paneRight = new LogPane();
		paneRight.updateDate(date.getYear(),date.getMonth(),date.getDate());
		paneRight.lbDate.setPrefWidth(date.getW());
		paneRight.taLog.setPrefSize(date.getW(), clock.getH() + date.getH() - 25);
		
		HBox hBoxBottom = new HBox(5);
		hBoxBottom.setAlignment(Pos.CENTER);
		hBoxBottom.setStyle("-fx-padding:10 10 10 10;");
		Button btnSaveLog = new Button("保存日志"),
				btnDelLog = new Button("删除日志"),
				btnOpenLog = new Button("读取日志");
		hBoxBottom.getChildren().addAll(btnSaveLog,btnDelLog,btnOpenLog);

		BorderPane mainPane = new BorderPane();
		mainPane.setLeft(paneLeft);
		mainPane.setTop(hBoxTop);
		mainPane.setCenter(paneRight);
		mainPane.setBottom(hBoxBottom);

		mainPane.setOnMouseClicked(e -> {
			paneRight.updateDate(date.getYear(),date.getMonth(),date.getDate());
		});
		btnLastYear.setOnAction(e -> {
			date.lastYear();
			tfYear.setText(date.getYear() + "");
			tfMonth.setText(date.getMonth() + "");
		});
		btnNextYear.setOnAction(e -> {
			date.nextYear();
			tfYear.setText(date.getYear() + "");
			tfMonth.setText(date.getMonth() + "");
		});
		btnLastMonth.setOnAction(e -> {
			date.lastMonth();
			tfYear.setText(date.getYear() + "");
			tfMonth.setText(date.getMonth() + "");
		});
		btnNextMonth.setOnAction(e -> {
			date.nextMonth();
			tfYear.setText(date.getYear() + "");
			tfMonth.setText(date.getMonth() + "");
		});
		tfYear.textProperty().addListener(ov -> {
			date.setYear(Integer.parseInt(tfYear.getText()));
			paneRight.updateDate(date.getYear(),date.getMonth(),date.getDate());
		});
		tfMonth.textProperty().addListener(ov -> {
			date.setMonth(Integer.parseInt(tfMonth.getText()));
			paneRight.updateDate(date.getYear(),date.getMonth(),date.getDate());
		});
		btnOpenLog.setOnAction(e -> {
			try {
				paneRight.openLog();
			} catch (FileNotFoundException e1) {
				e1.printStackTrace();
			}
		});
		btnDelLog.setOnAction(e -> {
			paneRight.delLog();
		});
		btnSaveLog.setOnAction(e -> {
			try {
				paneRight.saveLog();
			} catch (FileNotFoundException e1) {
				e1.printStackTrace();
			}
		});
		
		Scene scene = new Scene(mainPane);
		//primaryStage.setResizable(false);
		primaryStage.setTitle("shizhong");
		primaryStage.setScene(scene);
		primaryStage.show();
	}
}
