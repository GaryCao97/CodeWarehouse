package sy5;

import javax.swing.JOptionPane;

import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.HPos;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.GridPane;
import javafx.stage.Stage;

public class DateToDay extends Application {
	private TextField text1 = new TextField();
	private TextField text2 = new TextField();
	private String[] Day = {
			"星期一",
			"星期二",
			"星期三",
			"星期四",
			"星期五",
			"星期六",
			"星期日"
	};
	public void start(Stage primaryStage) {
		GridPane pane = new GridPane();
		pane.setAlignment(Pos.CENTER);
		pane.setPadding(new Insets(5, 5, 5, 5));
		pane.setHgap(2);
		pane.setVgap(2);

		Label label1 = new Label("输入数字");
		Label label2 = new Label("星期几");
		text1.setPrefWidth(200);
		text2.setPrefWidth(200);
		label1.setPrefWidth(200);
		label2.setPrefWidth(200);
		label1.setAlignment(Pos.CENTER_RIGHT);
		label2.setAlignment(Pos.CENTER_RIGHT);
		pane.add(label1, 0, 0);
		pane.add(text1, 1, 0);
		text1.setOnAction(new EventHandler<ActionEvent>(){
			public void handle(ActionEvent e) {
				int num = Integer.parseInt(text1.getText());
				if(num > 7 || num < 1)JOptionPane.showMessageDialog(null, "BadDataException:您输入的日子数不是1..7");
				else text2.setText(Day[num - 1]);
			}
		});
		pane.add(label2, 0, 1);
		pane.add(text2, 1, 1);
		GridPane.setHalignment(label1, HPos.RIGHT);
		GridPane.setHalignment(label2, HPos.RIGHT);
		
		Scene scene = new Scene(pane);
		primaryStage.setResizable(false);
		primaryStage.setTitle("日子数与星期几转换");
		primaryStage.setScene(scene);
		primaryStage.show();
	}
	public static void main(String[] args) {
		Application.launch(args);
	}
}
