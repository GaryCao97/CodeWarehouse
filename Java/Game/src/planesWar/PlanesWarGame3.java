package planesWar;

import java.util.ArrayList;

import javafx.animation.KeyFrame;
import javafx.animation.Timeline;
import javafx.application.Application;
import javafx.beans.property.SimpleBooleanProperty;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Ellipse;
import javafx.scene.shape.Polygon;
import javafx.stage.Stage;
import javafx.util.Duration;

public class PlanesWarGame3 extends Application {
	private final static double WIDTH = 800, HEIGHT = 800, PER_STEP = 10;
	double perX = 0,perY = 0;
	boolean isSendBullets = false;
	boolean isUP = false,isDOWN = false,isLEFT = false,isRIGHT = false;
	ArrayList<Planes> otherPlanes;
	Planes myPlane;
	SimpleBooleanProperty isEnd;
	Timeline createPlanes;
	Timeline moveAndHit;
	public void start(Stage primaryStage) throws Exception {
		// TODO 自动生成的方法存根
		Group gamePane = new Group();
		Scene scene = new Scene(gamePane,WIDTH,HEIGHT);
		isEnd = new SimpleBooleanProperty();
		isEnd.setValue(false);
		
		myPlane = new Planes();
		otherPlanes = new ArrayList<Planes>();
		gamePane.getChildren().add(myPlane);
		myPlane.setLayoutX(WIDTH / 2 - Planes.WIDTH / 2);
		myPlane.setLayoutY(HEIGHT - Planes.HEIGHT - 10);

		//动画1：每1秒生成一架敌机
		createPlanes = new Timeline(new KeyFrame(Duration.millis(1000), e1 -> {
			Planes op = new Planes(false);
			otherPlanes.add(op);
			gamePane.getChildren().add(op);
			op.setLayoutX(getRandom(0,WIDTH - Planes.WIDTH));
			op.setLayoutY(0);
			op.layoutYProperty().addListener(ov1 -> {
				if(op.getLayoutY() > HEIGHT) {
					otherPlanes.remove(op);
					gamePane.getChildren().remove(op);
				}
			});
			for(int o = 0;o < otherPlanes.size();o++) {
				otherPlanes.get(o).sendBullets();
				gamePane.getChildren().add(otherPlanes.get(o).getBullets().get(otherPlanes.get(o).getBullets().size()-1));				
			}
		}));
		createPlanes.setCycleCount(Timeline.INDEFINITE);
		createPlanes.play();
		
		//动画2：每刻进行飞机移动，子弹发射以及碰撞测试
		moveAndHit = new Timeline(new KeyFrame(Duration.millis(100), e2 -> {
			for(int i = 0;i < otherPlanes.size();i++) {
				if(otherPlanes.get(i).isHit(myPlane)) {
					isEnd.setValue(true);
					return;
				}
			}
			perX = (isLEFT?-PER_STEP:0) + (isRIGHT?PER_STEP:0);
			perY = (isUP?-PER_STEP:0) + (isDOWN?PER_STEP:0);
			myPlane.movePlane(perX, perY);
			if(isSendBullets) {
				myPlane.sendBullets();
				gamePane.getChildren().add(myPlane.getBullets().get(myPlane.getBullets().size()-1));
			}
			for(int i = 0;i < otherPlanes.size();i++) {
				for(int j = 0;j < otherPlanes.get(i).getBullets().size(); j++) {
					if(otherPlanes.get(i).getBullets().get(j).isHit(myPlane)) {
						isEnd.setValue(true);
						return;
					}
				}
				for(int j = 0;j < myPlane.getBullets().size(); j++) {
					if(myPlane.getBullets().get(j).isHit(otherPlanes.get(i))) {
						gamePane.getChildren().remove(otherPlanes.get(i));
						gamePane.getChildren().remove(myPlane.getBullets().get(j));
						otherPlanes.remove(i);
						myPlane.getBullets().remove(j);
						i--;
						break;
					}
				}
			}
		}));
		moveAndHit.setCycleCount(Timeline.INDEFINITE);
		moveAndHit.play();
		
		//游戏结束响应事件
		isEnd.addListener(lv -> {
			if(isEnd.get()) {
				stopAnimation();
				//gamePane.getChildren().clear();
				//otherPlanes.clear();
				//myPlane.getBullets().clear();
			}
		});
		
		//键盘事件响应函数
		scene.setOnKeyPressed(kp1 -> {
			switch(kp1.getCode()) {
			case UP:
				isUP = true;
				break;
			case DOWN:
				isDOWN = true;
				break;
			case LEFT:
				isLEFT = true;
				break;
			case RIGHT:
				isRIGHT = true;
				break;
			case SPACE:
				isSendBullets = true;
				break;
			default:
				break;
			}
		});
		scene.setOnKeyReleased(kp2 -> {
			switch(kp2.getCode()) {
			case UP:
				isUP = false;
				break;
			case DOWN:
				isDOWN = false;
				break;
			case LEFT:
				isLEFT = false;
				break;
			case RIGHT:
				isRIGHT = false;
				break;
			case SPACE:
				isSendBullets = false;
				break;
			default:
				break;
			}
		});
		
		primaryStage.setScene(scene);
		primaryStage.setTitle("飞机大战游戏");
		primaryStage.show();
	}
	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		launch(args);
	}
	void stopAnimation() {
		createPlanes.stop();
		moveAndHit.stop();
		for(int n = 0;n < otherPlanes.size();n++) {
			otherPlanes.get(n).stop();
			for(int m = 0;m < otherPlanes.get(n).getBullets().size();m++)
				otherPlanes.get(n).getBullets().get(m).stop();
		}
		for(int m = 0;m < myPlane.getBullets().size();m++)
			myPlane.getBullets().get(m).stop();
	}
	double getRandom(double left, double right) {
		return (Math.random() * (right - left + 1) + left);
	}
}
class Planes extends Pane {
	private Polygon plane;
	private boolean isMyPlanes;//
	private Timeline opAnimation;
	private ArrayList<Bullets> Bullets;
	
	static final double WIDTH = 20, HEIGHT = 50, PER_STEP = 10;
	private final double[][] myPlane = {{WIDTH / 2,0},{0,HEIGHT},{WIDTH / 2,HEIGHT * 3 / 4},{WIDTH,HEIGHT}};
	private final double[][] otherPlane = {{WIDTH / 2,HEIGHT},{0,0},{WIDTH / 2,HEIGHT * 1 / 4},{WIDTH,0}};
	private final Color myColor = Color.rgb(160, 40, 200);
	private final Color otherColor = Color.rgb(200, 60, 60);
	
	public Planes() {
		this(true);
	}
	public Planes(boolean isMyPlane) {
		Bullets = new ArrayList<Bullets>();
		opAnimation = null;
		setPrefSize(WIDTH, HEIGHT);
		isMyPlanes = isMyPlane;
		plane = new Polygon();
		getChildren().add(plane);
		double[][] planeArr = isMyPlanes? myPlane : otherPlane;
		Color color = isMyPlanes? myColor : otherColor;
		drawPlane(planeArr, color);
		if(!isMyPlanes) {
			opAnimation = new Timeline(new KeyFrame(Duration.millis(50), e -> {
				setLayoutY(getLayoutY() + PER_STEP);
			}));
			opAnimation.setCycleCount(Timeline.INDEFINITE);
			opAnimation.play();
		}
	}
	public void movePlane(double offsetX, double offsetY) {
		this.setLayoutX(this.getLayoutX() + offsetX);
		this.setLayoutY(this.getLayoutY() + offsetY);
	}
	public void sendBullets() {
		Bullets.add(new Bullets(this.getLayoutX() + WIDTH / 2, this.getLayoutY() - (isMyPlanes? 10 : -HEIGHT),isMyPlanes));
	}
	public ArrayList<Bullets> getBullets() { return Bullets; }
	void stop() { opAnimation.stop();}
	boolean isHit(Planes p) {
		double p1X = p.getLayoutX() + p.getWidth() / 2;
		double p1Y = p.getLayoutY() + p.getHeight() / 2;
		double p2X = this.getLayoutX() + this.getWidth() / 2;
		double p2Y = this.getLayoutY() + this.getHeight() / 2;
		double dis = Math.sqrt(Math.pow(p1X - p2X, 2) + Math.pow(p1Y - p2Y, 2));
		return dis < 25;
	}
	private void drawPlane(double[][] planeArr,Color color) {
		plane.setFill(color);
		plane.setStroke(Color.rgb(0, 0, 0));
		for(int i = 0;i < planeArr.length;i++) 
			for(int j = 0;j < planeArr[i].length;j++) 
				plane.getPoints().add(planeArr[i][j]);
	}
}
class Bullets extends Ellipse {
	final double PER_STEP_BULLETS = 5;
	private double bulletsSize;
	private boolean isMyBullets;
	private Timeline bulletsAnimation;
	public Bullets() {
		this(0,0,true,5);
	}
	public Bullets(double x,double y,boolean isMyBullet) {
		this(x,y,isMyBullet,5);
	}
	public Bullets(double x,double y,boolean isMyBullet,double BulletsSize) {
		isMyBullets = isMyBullet;
		bulletsSize = BulletsSize;
		this.setCenterX(x);
		this.setCenterY(y);
		this.setRadiusX(bulletsSize);
		this.setRadiusY(bulletsSize);
		if(isMyBullets) {
			bulletsAnimation = new Timeline(new KeyFrame(Duration.millis(50), e -> {
				this.setCenterY(this.getCenterY() - PER_STEP_BULLETS);
			}));
		}
		else {
			bulletsAnimation = new Timeline(new KeyFrame(Duration.millis(50), e -> {
				this.setCenterY(this.getCenterY() + PER_STEP_BULLETS + Planes.PER_STEP);
			}));
		}
		bulletsAnimation.setCycleCount(Timeline.INDEFINITE);
		bulletsAnimation.play();
	}
	boolean isHit(Planes p) {
		double pX = p.getLayoutX() + p.getWidth() / 2;
		double pY = p.getLayoutY() + p.getHeight() / 2;
		double bX = this.getCenterX(), bY = this.getCenterY();
		double dis = Math.sqrt(Math.pow(bX - pX, 2) + Math.pow(bY - pY, 2));
		return dis < 10;
	}
	void stop() { bulletsAnimation.stop();}
}
