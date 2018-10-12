package gobang;

import javafx.scene.Node;
import javafx.scene.layout.GridPane;

public class StatusBar extends GridPane {
	
	public StatusBar() {
	}
	public void setStatus(int index, Node statusCell) {
		this.add(statusCell, index, 0);
	}
}
