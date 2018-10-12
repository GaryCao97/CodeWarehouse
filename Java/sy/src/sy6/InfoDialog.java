package sy6;

import javafx.application.Application;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.ComboBox;
import javafx.scene.control.Label;
import javafx.scene.control.RadioButton;
import javafx.scene.control.TextField;
import javafx.scene.control.ToggleGroup;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.FlowPane;
import javafx.scene.layout.HBox;
import javafx.stage.Stage;

public class InfoDialog extends Application {
	public static void main(String[] args) {
		Application.launch(args);
	}
	public void start(Stage primaryStage) throws Exception {
		FlowPane centerPane = new FlowPane(5,5);
		centerPane.setAlignment(Pos.CENTER);
		HBox[] hPane = new HBox[6];
		Label[] lbText = {
				new Label("����"),
				new Label("�Ա�"),
				new Label("��ν"),
				new Label("������λ"),
				new Label("������ַ"),
				new Label("�绰1"),
				new Label("�绰2"),
				new Label("�ֻ�"),
				new Label("����"),
				new Label("E-mail")
		};
		TextField tfName = new TextField();
		tfName.setPrefColumnCount(6);
		RadioButton rbMale = new RadioButton("��");
		RadioButton rbFemale = new RadioButton("Ů");
		ToggleGroup sexGroup = new ToggleGroup();
		rbMale.setToggleGroup(sexGroup);
		rbFemale.setToggleGroup(sexGroup);
		ComboBox<String> cboChengwei = new ComboBox<>();
		cboChengwei.getItems().addAll("�ܲ�","�ܾ���","����","����","����","Ժ��","У��","�Ƴ�","����");
		TextField tfDanwei = new TextField();
		tfDanwei.setPrefColumnCount(24);
		TextField tfDizhi = new TextField();
		tfDizhi.setPrefColumnCount(24);
		TextField tfTel1 = new TextField();//�绰1
		tfTel1.setPrefColumnCount(10);
		TextField tfTel2 = new TextField();//�绰2
		tfTel2.setPrefColumnCount(10);
		TextField tfTel3 = new TextField();//�ֻ�
		tfTel3.setPrefColumnCount(10);
		TextField tfTel4 = new TextField();//����
		tfTel4.setPrefColumnCount(10);
		TextField tfEmail = new TextField();
		tfEmail.setPrefColumnCount(25);
		for(int n = 0;n < 6;n++) {
			hPane[n] = new HBox(5);
			hPane[n].setStyle("-fx-padding:3 3 3 0;");
			hPane[n].setAlignment(Pos.CENTER);
		}
		hPane[0].getChildren().addAll(
				lbText[0],tfName,
				lbText[1],rbMale,rbFemale,
				lbText[2],cboChengwei
		);
		hPane[1].getChildren().addAll(lbText[3],tfDanwei);
		hPane[2].getChildren().addAll(lbText[4],tfDizhi);
		hPane[3].getChildren().addAll(
				lbText[5],tfTel1,
				lbText[6],tfTel2
		);
		hPane[4].getChildren().addAll(
				lbText[7],tfTel3,
				lbText[8],tfTel4
		);
		hPane[5].getChildren().addAll(lbText[9],tfEmail);
		centerPane.getChildren().addAll(hPane);
		
		HBox hBoxBottom = new HBox(5);
		hBoxBottom.setAlignment(Pos.CENTER);
		hBoxBottom.setStyle("-fx-padding:10 10 10 10;");
		Button btnOK = new Button("ȷ��"),
				btnCancel = new Button("ȡ��");
		btnOK.setOnAction(e -> {
			String str = "������" + tfName.getText() + "\n�Ա�";
			if(rbMale.isSelected())str += "��";
			if(rbFemale.isSelected())str += "Ů";
			str += "\n��ν��" + cboChengwei.getValue();
			str += "\n��˾��λ��" + tfDanwei.getText();
			str += "\n��˾��ַ��" + tfDizhi.getText();
			str += "\n�绰1��" + tfTel1.getText();
			str += "\n�绰2��" + tfTel2.getText();
			str += "\n�ֻ���" + tfTel3.getText();
			str += "\n���棺" + tfTel4.getText();
			str += "\nE-mail��" + tfEmail.getText();
			Label lbStr = new Label(str);
			Scene sceneTmp = new Scene(lbStr,300,300);
			Stage stageTmp = new Stage();
			stageTmp.setResizable(false);
			stageTmp.setTitle("��Ƭ");
			stageTmp.setScene(sceneTmp);
			stageTmp.show();
		});
		btnCancel.setOnAction(e -> {
			primaryStage.close();
		});
		hBoxBottom.getChildren().addAll(btnOK,btnCancel);

		BorderPane mainPane = new BorderPane();
		mainPane.setCenter(centerPane);
		mainPane.setBottom(hBoxBottom);
		
		Scene scene = new Scene(mainPane);
		//primaryStage.setResizable(false);
		primaryStage.setTitle("��Ƭ¼��ϵͳ");
		primaryStage.setScene(scene);
		primaryStage.show();
	}
}
