package matchIt;

import java.io.InputStream;

import javafx.beans.property.DoubleProperty;
import javafx.beans.property.SimpleDoubleProperty;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.StackPane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;
import javafx.scene.shape.StrokeType;

public class MatchPic extends StackPane {
	static final double SIZE = 60, BORDER_SIZE = 5.0;
	static final double REAL_SIZE = SIZE + 2 * BORDER_SIZE;
	static final Color[] bgColor = {
			
	};
	static DoubleProperty realSize = new SimpleDoubleProperty(REAL_SIZE);
	private int picNum;
	private Rectangle bg;
	private ImageView pic;
	private boolean isChecked;
	
	public MatchPic(int type) {
		picNum = type;
		bg = new Rectangle(0,0,SIZE,SIZE);
		bg.setStrokeWidth(BORDER_SIZE);
		bg.setStrokeType(StrokeType.OUTSIDE);
		bg.setStroke(Color.rgb(0, 0, 0));
		isChecked = false;
		bg.setFill(Color.WHITE);
		this.getChildren().add(bg);
		if(type != 0) {
			pic = new ImageView(new Image(this.getImage(picNum)));
			pic.setFitHeight(SIZE);
			pic.setFitWidth(SIZE);
			this.getChildren().add(pic);
		}
		realSize.bind(this.widthProperty());
	}
	public void setPicChecked(boolean isChecked) {
		if(picNum != 0) {
			this.isChecked = isChecked;
			if(isChecked) {
				bg.setStroke(Color.rgb(255, 128, 0));
			}
			else {
				bg.setStroke(Color.rgb(0, 0, 0));
			}
		}
	}
	public boolean getPicChecked() {
		return isChecked;
	}
	public boolean canMatch(MatchPic mp) {
		return mp.getPicNum() == this.getPicNum();
	}
	public int getPicNum() {
		return picNum;
	}
	public void setPicType(int picType) {
		picNum = picType;
		if(picType != 0) {
			pic.setImage(new Image(this.getImage(picNum)));
			pic.setFitHeight(SIZE);
			pic.setFitWidth(SIZE);
			if(!this.getChildren().contains(pic))
				this.getChildren().add(pic);
		}
		else {
			bg.setStroke(Color.rgb(0, 0, 0));
			this.getChildren().remove(pic);
		}
	}
	public void setHint() {
		bg.setStroke(Color.rgb(0, 128, 255));
	}

	private InputStream getImage(int i) {
		return /*"file:" + */getClass().getResourceAsStream("/PokerCardImage/" + (i) + ".jpg");
	}
}
