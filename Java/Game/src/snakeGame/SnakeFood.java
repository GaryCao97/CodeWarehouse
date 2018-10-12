package snakeGame;

import java.util.ArrayList;

import javafx.scene.Group;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Polygon;

public class SnakeFood {
	static final double WIDTH = Snake.WIDTH, HEIGHT = Snake.HEIGHT;
	static ArrayList<Food> foods = new ArrayList<Food>();
	static Group parent;
	static int foodsNum = 0;
	static void bindParent(Group p) {parent = p;}
	static void createFood() {
		if(foodsNum<3) {
			double x = getRandom(SnakeNode.SIZE,WIDTH - SnakeNode.SIZE);
			double y = getRandom(SnakeNode.SIZE,HEIGHT - SnakeNode.SIZE);
			x = ((int)(x / Food.SIZE)) * Food.SIZE;
			y = ((int)(y / Food.SIZE)) * Food.SIZE;
			Food f = new Food(x,y,(int)getRandom(0,Food.LEVEL - 1));
			foods.add(f);
			parent.getChildren().add(f);
			foodsNum++;
		}
	}
	static void deleteFood(int index) {
		parent.getChildren().remove(foods.get(index));
		foods.remove(index);
		foodsNum--;
	}
	static void restart() {
		foods.clear();
		foodsNum = 0;
	}
	static double getRandom(double left, double right) {
		return (Math.random() * (right - left) + left);
	}
}

class Food extends Pane {
	Polygon foodShape;
	private int score;
	static final double SIZE = SnakeNode.SIZE;
	static final int LEVEL = 4;
	private final int[] scoreArr = {1,2,4,8};
	private final double[][][] foodArr = {
			{{SIZE/2,0},{0,SIZE*3/7},{SIZE*2/7,SIZE},{SIZE*5/7,SIZE},{SIZE,SIZE*3/7}},
			{{SIZE/2,0},{0,SIZE/3},{0,SIZE*2/3},{SIZE/2,SIZE},{SIZE,SIZE*2/3},{SIZE,SIZE/3}},
			{{SIZE/2,0},{0,SIZE/3},{0,SIZE*2/3},{SIZE/3,SIZE},{SIZE*2/3,SIZE},{SIZE,SIZE*2/3},{SIZE,SIZE/3}},
			{{SIZE/3,0},{SIZE*2/3,0},{SIZE,SIZE/3},{SIZE,SIZE*2/3},{SIZE*2/3,SIZE},{SIZE/3,SIZE},{0,SIZE*2/3},{0,SIZE/3}}
	};
	public Food(double x,double y,int level) {
		score = scoreArr[level];
		foodShape = new Polygon();
		foodShape.setFill(Color.rgb(100, 0, 100));
		foodShape.setStroke(Color.rgb(0, 0, 0));
		for(int i = 0;i < foodArr[level].length;i++) 
			for(int j = 0;j < foodArr[level][i].length;j++) 
				foodShape.getPoints().add(foodArr[level][i][j]);
		this.getChildren().add(foodShape);
		this.setLayoutX(x);
		this.setLayoutY(y);
	}
	public int getScore() {return score;}
}