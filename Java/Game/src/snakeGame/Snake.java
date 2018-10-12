package snakeGame;

import java.util.ArrayList;

import javafx.beans.property.IntegerProperty;
import javafx.beans.property.SimpleIntegerProperty;
import javafx.scene.Group;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Polygon;

public class Snake extends Group{
	static final double WIDTH = 400, HEIGHT = 400,PER_STEP = SnakeNode.SIZE;
	int length;
	ArrayList<SnakeNode> snake;
	ArrayList<Position> directStack;
	IntegerProperty score;
	public Snake() {
		score = new SimpleIntegerProperty();
		score.set(0);
		Position nowDirect = new Position(0,PER_STEP);
		directStack = new ArrayList<Position>();
		length = 3;
		snake = new ArrayList<SnakeNode>();
		SnakeNode p = new SnakeNode(true,WIDTH/2,HEIGHT/2);
		snake.add(p);
		this.getChildren().add(p);
		p.setDirection(nowDirect);
		for(int i = 1;i < length;i++) {
			p = new SnakeNode(false,snake.get(i-1).position.subtract(snake.get(i-1).direction));
			p.setDirection(nowDirect);
			snake.add(p);
			this.getChildren().add(p);
		}
		directStack.add(nowDirect);
	}
	public void restart() {
		this.getChildren().clear();
		score.set(0);
		length = 3;
		snake.clear();
		directStack.clear();
		Position nowDirect = new Position(0,PER_STEP);
		SnakeNode p = new SnakeNode(true,WIDTH/2,HEIGHT/2);
		snake.add(p);
		this.getChildren().add(p);
		p.setDirection(nowDirect);
		for(int i = 1;i < length;i++) {
			p = new SnakeNode(false,snake.get(i-1).position.subtract(nowDirect));
			p.setDirection(nowDirect);
			snake.add(p);
			this.getChildren().add(p);
		}
		directStack.add(nowDirect);
	}
	public void growUp() {
		SnakeNode p = new SnakeNode(false,snake.get(length-1).position.subtract(snake.get(length-1).direction));
		p.setDirection(snake.get(length-1).position.subtract(p.position));
		snake.add(p);
		this.getChildren().add(p);
		length = snake.size();
	}
	public void moveSnake() {
		Position perDirect = new Position(directStack.get(0));
		if(directStack.size() > 1)
			directStack.remove(0);
		snake.get(0).setDirection(perDirect);
		for(int i = 1;i<snake.size();i++) {
			perDirect = snake.get(i-1).position.subtract(snake.get(i).position);
			snake.get(i).setDirection(perDirect);
		}
		for(int i = 0;i <snake.size();i++) {
			snake.get(i).moveSnakeNode();
		}
		setOutOfArea();
	}
	public void addDirect(Position d) {
		if(directStack.get(directStack.size() - 1).notEqual(d))
			directStack.add(d);
	}
	public boolean snakeEatFood() {
		for(int n = 0;n < SnakeFood.foods.size();n++) {
			if(SnakeFood.foods.get(n).getLayoutX() == snake.get(0).getLayoutX()
					&& SnakeFood.foods.get(n).getLayoutY() == snake.get(0).getLayoutY()) {
				growUp();
				score.set(score.get() + SnakeFood.foods.get(n).getScore());
				SnakeFood.deleteFood(n);
				return true;
			}
		}
		return false;
	}
	public void setOutOfArea() {
		if(snake.get(0).getLayoutX() < 0) {
			snake.get(0).setLayoutX(WIDTH - SnakeNode.SIZE);
			snake.get(0).position.setX(WIDTH - SnakeNode.SIZE);
		}
		if(snake.get(0).getLayoutY() < 0) {
			snake.get(0).setLayoutY(HEIGHT - SnakeNode.SIZE);
			snake.get(0).position.setY(HEIGHT - SnakeNode.SIZE);
		}
		if(snake.get(0).getLayoutX() > (WIDTH - SnakeNode.SIZE)) {
			snake.get(0).setLayoutX(0);
			snake.get(0).position.setX(0);
		}
		if(snake.get(0).getLayoutY() > (HEIGHT - SnakeNode.SIZE)) {
			snake.get(0).setLayoutY(0);
			snake.get(0).position.setY(0);
		}
	}
	public boolean selfHit() {
		Position perPos = new Position(snake.get(0).position);
		for(int i = 1;i<snake.size();i++) 
			if(!perPos.notEqual(snake.get(i).position))
				return true;
		return false;
	}
	public boolean wallsHit() {
		Position headPos = new Position(snake.get(0).position);
		for(int i = 0;i < SnakeWall.walls.size();i++) 
			if(!headPos.notEqual(SnakeWall.walls.get(i).pos))
				return true;
		return false;
	}
}

class SnakeNode extends Pane {
	private Polygon snakeNode;
	private boolean isHead;//
	Position position;
	Position direction;
	static final double SIZE = 20;
	private final double[][] snakeHead = {{0,SIZE / 2},{SIZE / 2,0},{SIZE,SIZE / 2},{SIZE / 2,SIZE}};
	private final double[][] snakeBody = {{0,0},{0,SIZE},{SIZE,SIZE},{SIZE,0}};
	private final Color headColor = Color.rgb(160, 40, 200);
	private final Color bodyColor = Color.rgb(200, 60, 60);
	public SnakeNode() {
		this(false,0,0);
	}
	public SnakeNode(boolean isHead,double x,double y) {
		this(isHead,new Position(x,y));
	}
	public SnakeNode(boolean isHead,Position p) {
		this.isHead = isHead;
		position = new Position(p);
		direction = new Position(0,0);
		snakeNode = new Polygon();
		getChildren().add(snakeNode);
		double[][] snakeArr = this.isHead? snakeHead : snakeBody;
		Color color = this.isHead? headColor : bodyColor;
		drawSnakeNode(snakeArr,color);
		setLayoutX(position.x);
		setLayoutY(position.y);
	}
	public void moveSnakeNode() {
		position = position.add(direction);
		this.setLayoutX(position.x);
		this.setLayoutY(position.y);
	}
	public void setDirection(Position d) {
		direction.setXY(d);
	}
 	public void setPosition(Position p) {
		position.setXY(p);
	}
	private void drawSnakeNode(double[][] snakeArr,Color color) {
		snakeNode.setFill(color);
		snakeNode.setStroke(Color.rgb(0, 0, 0));
		for(int i = 0;i < snakeArr.length;i++) 
			for(int j = 0;j < snakeArr[i].length;j++) 
				snakeNode.getPoints().add(snakeArr[i][j]);
	}
}

class Position {
	double  x,y;
	public Position(double x,double y) {
		this.x = x;
		this.y = y;
	}
	public Position(Position p) {
		this.x = p.x;
		this.y = p.y;
	}
	public void setXY(Position p) {
		this.x = p.x;
		this.y = p.y;
	}
	public void setXY(double x,double y) {
		this.x = x;
		this.y = y;
	}
	public void setX(double x) {this.x = x;}
	public void setY(double y) {this.y = y;}
	public Position add(Position p) {
		return new Position(x + p.x,y + p.y);
	}
	public Position subtract(Position p) {
		return new Position(x - p.x,y - p.y);
	}
	public Position multiply(Position p) {
		return new Position(x * p.x,y * p.y);
	}
	public boolean notEqual(Position p) {
		return (x != p.x || y != p.y);
	}
}