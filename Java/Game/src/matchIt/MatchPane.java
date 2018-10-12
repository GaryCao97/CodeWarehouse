package matchIt;

import java.util.ArrayList;
import java.util.Collections;

import javafx.animation.Animation.Status;
import javafx.animation.KeyFrame;
import javafx.animation.Timeline;
import javafx.beans.property.IntegerProperty;
import javafx.beans.property.SimpleIntegerProperty;
import javafx.scene.Group;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.Pane;
import javafx.scene.layout.StackPane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Line;
import javafx.scene.shape.Rectangle;
import javafx.scene.text.Text;
import javafx.util.Duration;

public class MatchPane extends Pane {
	static final int WIDTH = 20, HEIGHT = 10;
	static final int[] picsNum = {13,26,26,26,39,39,39,39,52,52};
	private int pairLeft = WIDTH * HEIGHT;
	private Group matchPane;
	private int[][] matchMap;
	private MatchPic[][] picMap;
	private GridPane picPane;
	private int lastX = -1,lastY = -1,nowX,nowY;
	private ArrayList<Pos> lines;
	private Timeline animation;
	private Pos hintA = new Pos(-1,-1),hintB = new Pos(-1,-1);
	private int level;
	private IntegerProperty score;
	private IntegerProperty timer;
	private Rectangle realTimeLine;
	private Rectangle timeLine;
	private Timeline timeAnime;
	private Btn btnHint;
	private Btn btnRestart;
	private Btn btnNext;
	
	public MatchPane() {
		this.level = 0;
		pairLeft = WIDTH * HEIGHT;
		lines = new ArrayList<Pos>();
		matchPane = new Group();
		picPane = new GridPane();
		this.getChildren().add(matchPane);
		//matchPane.setAutoSizeChildren(true);
		this.setPrefSize(((WIDTH + 2) * MatchPic.REAL_SIZE), ((HEIGHT + 2) * MatchPic.REAL_SIZE) + 60);//?
		picPane.setLayoutX(MatchPic.REAL_SIZE);
		picPane.setLayoutY(MatchPic.REAL_SIZE + 60);
		matchMap = new int[HEIGHT + 4][WIDTH + 4];
		picMap = new MatchPic[HEIGHT][WIDTH];
		for(int i = 0;i < matchMap.length;i++) 
			for(int j = 0;j < matchMap[i].length;j++) {
				matchMap[i][j] = 0;
				if(i == 0 || j == 0 || i == matchMap.length-1 || j == matchMap[i].length-1)
					matchMap[i][j] = -1;
			}
		ArrayList<Integer> nums = new ArrayList<Integer>();
		for(int i = 0;i < (WIDTH * HEIGHT / 2);i++) {
			int j = getRandInteger(1,picsNum[level]);
			nums.add(new Integer(j));
			nums.add(new Integer(j));
		}
		Collections.shuffle(nums);
		for(int i = 0;i < picMap.length;i++) 
			for(int j = 0;j < picMap[i].length;j++) {
				int k = nums.get(0);
				nums.remove(0);
				picMap[i][j] = new MatchPic(k);
				picPane.add(picMap[i][j], j, i);
				matchMap[i+2][j+2] = k;
			}
		while(isDead()) {
			shuffle();
		}
		matchPane.getChildren().add(picPane);
		score = new SimpleIntegerProperty(0);
		timer = new SimpleIntegerProperty(60*1000);
		timer.addListener(l -> {
			int w = (int) (timer.get() * ((WIDTH - 2) * MatchPic.REAL_SIZE / (timer.get() >= 60000 ? timer.get() : 60000)));
			timeLine.setWidth(w);
		});
		timeLine = new Rectangle(0,0,(WIDTH - 2) * MatchPic.REAL_SIZE,30);
		timeLine.setFill(Color.rgb(100, 200, 150));
		timeLine.setStroke(Color.rgb(0, 0, 0));
		realTimeLine = new Rectangle(0,0,(WIDTH - 2) * MatchPic.REAL_SIZE,30);
		realTimeLine.setStroke(Color.rgb(0, 0, 0));
		matchPane.getChildren().add(realTimeLine);
		realTimeLine.setLayoutX(MatchPic.REAL_SIZE * 2);
		realTimeLine.setLayoutY(30);
		timeAnime = new Timeline(new KeyFrame(Duration.millis(1), kf -> {
			timer.set(timer.get() - 1);
			if(timer.get() <= 0)timeAnime.stop();
		}));
		timeAnime.setCycleCount(Timeline.INDEFINITE);
		timeAnime.play();
		matchPane.getChildren().add(timeLine);
		timeLine.setLayoutX(MatchPic.REAL_SIZE * 2);
		timeLine.setLayoutY(30);
		btnHint = new Btn("提示",30,30);
		btnHint.setOnMouseClicked(mc0 -> {
			this.hint();
		});
		matchPane.getChildren().add(btnHint);
		btnHint.setLayoutY(30);
		btnRestart = new Btn("重来",30,30);
		btnRestart.setOnMouseClicked(mc0 -> {
			this.restart();
		});
		matchPane.getChildren().add(btnRestart);
		btnRestart.setLayoutX(30);
		btnRestart.setLayoutY(30);
		btnNext = new Btn("下一关",MatchPic.REAL_SIZE,MatchPic.REAL_SIZE);
		btnNext.setOnMouseClicked(mc0 -> {
			this.setLevel(this.level + 1);
		});
		btnNext.setLayoutX((WIDTH / 2) * MatchPic.REAL_SIZE);
		btnNext.setLayoutY((HEIGHT / 2) * MatchPic.REAL_SIZE + 60);
		picPane.setOnMouseClicked(mc -> {
			nowX = (int)(mc.getX() / MatchPic.realSize.get());
			nowY = (int)(mc.getY() / MatchPic.realSize.get());
			if(picMap[nowY][nowX].getPicNum() == 0) {
				if(lastX != -1 && lastY != -1)
					picMap[lastY][lastX].setPicChecked(false);
				lastX = -1;
				lastY = -1;
			}
			else if(picMap[nowY][nowX].getPicChecked()) {
				picMap[nowY][nowX].setPicChecked(false);
				lastX = -1;
				lastY = -1;
			}
			else if(lastX == -1 || lastY == -1) {
				lastX = nowX;
				lastY = nowY;
				picMap[nowY][nowX].setPicChecked(true);
			}
			else if(canMatch(nowX+2,nowY+2,lastX+2,lastY+2)) {
				picMap[nowY][nowX].setPicChecked(false);
				picMap[lastY][lastX].setPicChecked(false);
				getMatchLine(nowX+2,nowY+2,lastX+2,lastY+2);
				drawLine();
				this.deleteAndMove(nowX, nowY, lastX, lastY);
				lastX = -1;
				lastY = -1;
				timer.set(timer.get() + 1000 * (52 / picsNum[level]));
				pairLeft -= 2;
			}
			else {
				picMap[nowY][nowX].setPicChecked(true);
				picMap[lastY][lastX].setPicChecked(false);
				lastX = nowX;
				lastY = nowY;
			}
			if(isEnd()) {
				matchPane.getChildren().add(btnNext);
				timeAnime.pause();
			}
			else {
				while(isDead()) {
					shuffle();
				}
			}
			//System.out.println(nowX + " " + nowY);
		});
	}
	public void setLevel(int level) {
		if(level < 0 || level > 9)return;
		this.level = level;
		score.set(0);
		timer.set(60 * 1000);
		this.restart();
	}
	public void hint() {
		//System.out.println(hintA.getX() + " " + hintA.getY());
		if(hintA.getX() != -1) {
			picMap[hintA.getY() - 2][hintA.getX() - 2].setHint();
			picMap[hintB.getY() - 2][hintB.getX() - 2].setHint();
		}
	}
	public void restart() {
		if(matchPane.getChildren().contains(btnNext))
			matchPane.getChildren().remove(btnNext);
		if(timeAnime.getStatus() == Status.PAUSED)
			timeAnime.play();
		pairLeft = WIDTH * HEIGHT;
		for(int i = 0;i < matchMap.length;i++) 
			for(int j = 0;j < matchMap[i].length;j++) {
				matchMap[i][j] = 0;
				if(i == 0 || j == 0 || i == matchMap.length-1 || j == matchMap[i].length-1)
					matchMap[i][j] = -1;
			}
		ArrayList<Integer> nums = new ArrayList<Integer>();
		for(int i = 0;i < (WIDTH * HEIGHT / 2);i++) {
			int j = getRandInteger(1,picsNum[level]);
			nums.add(new Integer(j));
			nums.add(new Integer(j));
		}
		Collections.shuffle(nums);
		for(int i = 0;i < picMap.length;i++) 
			for(int j = 0;j < picMap[i].length;j++) {
				int k = nums.get(0);
				nums.remove(0);
				picMap[i][j].setPicType(k);
				matchMap[i+2][j+2] = k;
			}
		while(isDead()) {
			shuffle();
		}
	}

	private boolean isEnd() {
		if(pairLeft <= 0) {
			return true;
		}
		return false;
	}
	private void deleteAndMove(int x0,int y0,int x1,int y1) {		
		matchMap[y0+2][x0+2] = 0;
		matchMap[y1+2][x1+2] = 0;
		picMap[y0][x0].setPicType(0);
		picMap[y1][x1].setPicType(0);		
		//2上 3左 4下 5右 6上下汇聚 7左右汇聚 8上下分离 9左右分离
		switch(level) {
		case 2:
			moveLineUp(x0,0,HEIGHT-1);
			moveLineUp(x1,0,HEIGHT-1);
			break;
		case 3:
			moveLineLeft(x0,0,WIDTH-1);
			moveLineLeft(x1,0,WIDTH-1);
			break;
		case 4:
			moveLineDown(x0,HEIGHT-1,0);
			moveLineDown(x1,HEIGHT-1,0);
			break;
		case 5:
			moveLineRight(x0,WIDTH-1,0);
			moveLineRight(x1,WIDTH-1,0);
			break;
		case 6:
			if(y0 > HEIGHT/2)moveLineUp(x0,HEIGHT/2,HEIGHT-1);
			else moveLineDown(x0,HEIGHT/2-1,0);
			if(y1 > HEIGHT/2)moveLineUp(x1,HEIGHT/2,HEIGHT-1);
			else moveLineDown(x1,HEIGHT/2-1,0);
			break;
		case 7:
			if(x0 > WIDTH/2)moveLineLeft(y0,WIDTH/2,WIDTH-1);
			else moveLineRight(y0,WIDTH/2-1,0);
			if(x1 > WIDTH/2)moveLineLeft(y1,WIDTH/2,WIDTH-1);
			else moveLineRight(y1,WIDTH/2-1,0);
			break;
		case 8:
			if(y0 < HEIGHT/2)moveLineUp(x0,0,HEIGHT/2-1);
			else moveLineDown(x0,HEIGHT-1,HEIGHT/2);
			if(y1 < HEIGHT/2)moveLineUp(x1,0,HEIGHT/2-1);
			else moveLineDown(x1,HEIGHT-1,HEIGHT/2);
			break;
		case 9:
			if(x0 < WIDTH/2)moveLineLeft(y0,0,WIDTH/2-1);
			else moveLineRight(y0,WIDTH-1,WIDTH/2);
			if(x1 < WIDTH/2)moveLineLeft(y1,0,WIDTH/2-1);
			else moveLineRight(y1,WIDTH-1,WIDTH/2);
			break;
		}
	}
	private void moveLineUp(int x,int start,int end) {
		for(int n = start + 1;n <= end && matchMap[n + 2][x + 2] != -1;n++) {
			if(picMap[n - 1][x].getPicNum() == 0) {
				int tmp = matchMap[n + 2 - 1][x + 2];
				matchMap[n + 2 - 1][x + 2] = matchMap[n + 2][x + 2];
				matchMap[n + 2][x + 2] = tmp;
				picMap[n - 1][x].setPicType(matchMap[n + 2 - 1][x + 2]);
				picMap[n][x].setPicType(matchMap[n + 2][x + 2]);
				System.out.println(matchMap[n + 2 - 1][x + 2]);
			}
		}
		//(new Scanner(System.in)).next();
	}
	private void moveLineDown(int x,int start,int end) {
		for(int n = start - 1;n >= end && matchMap[n + 2][x + 2] != -1;n--) {
			if(picMap[n + 1][x].getPicNum() == 0) {
				int tmp = matchMap[n + 2 + 1][x + 2];
				matchMap[n + 2 + 1][x + 2] = matchMap[n + 2][x + 2];
				matchMap[n + 2][x + 2] = tmp;
				picMap[n + 1][x].setPicType(matchMap[n + 2 + 1][x + 2]);
				picMap[n][x].setPicType(matchMap[n + 2][x + 2]);
				//System.out.println(x+" "+start + " " + end);
			}
		}
	}
	private void moveLineLeft(int y,int start,int end) {
		//System.out.println(x+" "+y);
		for(int n = start + 1;n <= end && matchMap[y + 2][n + 2] != -1;n++) {
			if(picMap[y][n - 1].getPicNum() == 0) {
				int tmp = matchMap[y + 2][n + 2 - 1];
				matchMap[y + 2][n + 2 - 1] = matchMap[y + 2][n + 2];
				matchMap[y + 2][n + 2] = tmp;
				picMap[y][n - 1].setPicType(matchMap[y + 2][n + 2 - 1]);
				picMap[y][n].setPicType(matchMap[y + 2][n + 2]);
			}
		}
	}
	private void moveLineRight(int y,int start,int end) {
		for(int n = start - 1;n >= end && matchMap[y + 2][n + 2] != -1;n--) {
			if(picMap[y][n + 1].getPicNum() == 0) {
				int tmp = matchMap[y + 2][n + 2 + 1];
				matchMap[y + 2][n + 2 + 1] = matchMap[y + 2][n + 2];
				matchMap[y + 2][n + 2] = tmp;
				picMap[y][n + 1].setPicType(matchMap[y + 2][n + 2 + 1]);
				picMap[y][n].setPicType(matchMap[y + 2][n + 2]);
			}
		}
	}
	private void shuffle() {
		ArrayList<Pos> pos = new ArrayList<Pos>();
		ArrayList<Integer> type = new ArrayList<Integer>();
		for(int i = 0;i < matchMap.length;i++) {
			for(int j = 0;j < matchMap[i].length;j++) {
				if(matchMap[i][j] > 0) {
					pos.add(new Pos(i,j));
					type.add(new Integer(matchMap[i][j]));
				}
			}
		}
		Collections.shuffle(type);
		while(pos.size() != 0) {
			int i = pos.get(pos.size() - 1).getX();
			int j = pos.get(pos.size() - 1).getY();
			pos.remove(pos.size() - 1);
			matchMap[i][j] = type.get(type.size() - 1);
			type.remove(type.size() - 1);
			picMap[i-2][j-2].setPicType(matchMap[i][j]);
		}
	}
	private boolean isDead() {
	    for(int i = 0;i < HEIGHT;++i){
	        for(int j = 0;j < WIDTH;++j){
	            if(matchMap[i+2][j+2] != 0){
	                for(int x = 0;x < HEIGHT;++x){
	                	int y;
	                    if(x == i)
	                    	y = j + 1;
	                    else
	                    	y = 0;
	                    for(;y < WIDTH;++y){
	                        if(matchMap[x+2][y+2] == matchMap[i+2][j+2]){
	                            if(canMatch(j+2,i+2,y+2,x+2)){
	                                hintA.setX(j+2);
	                                hintA.setY(i+2);
	                                hintB.setX(y+2);
	                                hintB.setY(x+2);
	                                return false;
	                            }
	                        }
	                    }
	                }
	            }
	        }
	    }
	    return true;
	}
	private void drawLine() {
		ArrayList<Line> ls = new ArrayList<Line>();
		animation = new Timeline(new KeyFrame(Duration.millis(1), kf -> {
			double sx = lines.get(0).getX(),sy = lines.get(0).getY(),ex = lines.get(1).getX(),ey = lines.get(1).getY();
			lines.remove(0);
			lines.remove(0);
			do {
				Line l = new Line((sx - 0.5) * MatchPic.REAL_SIZE,(sy - 0.5) * MatchPic.REAL_SIZE + 60,
						(ex - 0.5) * MatchPic.REAL_SIZE,(ey - 0.5) * MatchPic.REAL_SIZE + 60);
				l.setStroke(Color.RED);
				l.setStrokeWidth(5);
				ls.add(l);
				this.getChildren().add(l);
				sx = ex;
				sy = ey;
				if(lines.size()!=0) {
					ex = lines.get(0).getX();
					ey = lines.get(0).getY();
					lines.remove(0);
				}
				else 
					break;
			}while(true);
		}),new KeyFrame(Duration.millis(200), kf -> {
			while(ls.size() != 0) {
				this.getChildren().remove(ls.get(0));
				ls.remove(0);
			}
		}));
		animation.setCycleCount(1);
		animation.play();
	}
	private boolean canMatch(int x0,int y0,int x1,int y1) {
		if(matchMap[y0][x0] != matchMap[y1][x1])return false;//扫描开始
		int step = 0,start0,end0,start1,end1;
		//横向扫描
		step = x1 > x0 ? (+1) : (-1);
		start0 = x0-1;
		end0 = x0+1;
		start1 = x1-1;
		end1 = x1+1;
		while(matchMap[y0][start0]==0 && matchMap[y0][start0--]==0); 
		start0++;
		while(matchMap[y0][end0]==0 && matchMap[y0][end0++]==0); 
		end0--;
		while(matchMap[y1][start1]==0 && matchMap[y1][start1--]==0); 
		start1++;
		while(matchMap[y1][end1]==0 && matchMap[y1][end1++]==0); 
		end1--;
		for(int i = x0;between(start0,end0,i);i+=step) 
			if(between(start1,end1,i) && canDirectLink(i,y0,i,y1)) 
				return true;
		step = 0 - step;
		for(int i = x0;between(start0,end0,i);i+=step) {
			if(!between(start1,end1,i))
				break;
			else if(canDirectLink(i,y0,i,y1)) 
				return true;
		}
		//纵向扫描
		step = y1 > y0 ? (+1) : (-1);
		start0 = y0-1;
		end0 = y0+1;
		start1 = y1-1;
		end1 = y1+1;
		while(matchMap[start0][x0]==0 && matchMap[start0--][x0]==0); 
		start0++;
		while(matchMap[end0][x0]==0 && matchMap[end0++][x0]==0); 
		end0--;
		while(matchMap[start1][x1]==0 && matchMap[start1--][x1]==0); 
		start1++;
		while(matchMap[end1][x1]==0 && matchMap[end1++][x1]==0); 
		end1--;
		for(int j = y0;between(start0,end0,j);j+=step) 
			if(between(start1,end1,j) && canDirectLink(x0,j,x1,j)) 
				return true;
		step = 0 - step;
		for(int j = y0;between(start0,end0,j);j+=step) {
			if(!between(start1,end1,j))
				break;
			else if(canDirectLink(x0,j,x1,j)) 
				return true;
		}
		return false;
	}
	private boolean getMatchLine(int x0,int y0,int x1,int y1) {
		lines.clear();
		lines.add(new Pos(x0,y0));
		//System.out.println(x0 + " " + y0 + ":" + x1 + " " + y1);
		//扫描开始
		int step = 0,start0,end0,start1,end1;
		//横向扫描
		step = x1 > x0 ? (+1) : (-1);
		start0 = x0-1;
		end0 = x0+1;
		start1 = x1-1;
		end1 = x1+1;
		while(matchMap[y0][start0]==0 && matchMap[y0][start0--]==0); 
		start0++;
		while(matchMap[y0][end0]==0 && matchMap[y0][end0++]==0); 
		end0--;
		while(matchMap[y1][start1]==0 && matchMap[y1][start1--]==0); 
		start1++;
		while(matchMap[y1][end1]==0 && matchMap[y1][end1++]==0); 
		end1--;
		//System.out.println(start0 + " " + end0 + ":" + start1 + " " + end1);
		for(int i = x0;between(start0,end0,i);i+=step) {
			if(between(start1,end1,i) && canDirectLink(i,y0,i,y1)) {
				if(i != x0)lines.add(new Pos(i,y0));
				if(i != x1)lines.add(new Pos(i,y1));
				lines.add(new Pos(x1,y1));
				return true;
			}
		}
		step = 0 - step;
		for(int i = x0;between(start0,end0,i);i+=step) {
			if(!between(start1,end1,i)){
				break;
			}
			else if(canDirectLink(i,y0,i,y1)) {
				if(i != x0)lines.add(new Pos(i,y0));
				if(i != x1)lines.add(new Pos(i,y1));
				lines.add(new Pos(x1,y1));
				return true;
			}
		}
		//纵向扫描
		step = y1 > y0 ? (+1) : (-1);
		start0 = y0-1;
		end0 = y0+1;
		start1 = y1-1;
		end1 = y1+1;
		while(matchMap[start0][x0]==0 && matchMap[start0--][x0]==0); 
		start0++;
		while(matchMap[end0][x0]==0 && matchMap[end0++][x0]==0); 
		end0--;
		while(matchMap[start1][x1]==0 && matchMap[start1--][x1]==0); 
		start1++;
		while(matchMap[end1][x1]==0 && matchMap[end1++][x1]==0); 
		end1--;
		for(int j = y0;between(start0,end0,j);j+=step) {
			if(between(start1,end1,j) && canDirectLink(x0,j,x1,j)) {
				if(j != y0)lines.add(new Pos(x0,j));
				if(j != y1)lines.add(new Pos(x1,j));
				lines.add(new Pos(x1,y1));
				return true;
			}
		}
		step = 0 - step;
		for(int j = y0;between(start0,end0,j);j+=step) {
			if(!between(start1,end1,j)){
				break;
			}
			else if(canDirectLink(x0,j,x1,j)) {
				if(j != y0)lines.add(new Pos(x0,j));
				if(j != y1)lines.add(new Pos(x1,j));
				lines.add(new Pos(x1,y1));
				return true;
			}
		}
		//lines.add(new Pos(x1,y1));
		return false;
	}
	private boolean between(int left,int right,int num) {
		return (num >= left && num <= right);
	}
	private boolean canDirectLink(int x0,int y0,int x1,int y1) {
		if(x0 == x1 && y0 == y1)return true;
		else if(x0 != x1 && y0 != y1)return false;
		else if(x0 == x1) {
			int sy = y0 > y1 ? y1 : y0;
			int ey = y0 < y1 ? y1 : y0;
			for(int j = sy;j < ey;j++) {
				if(j!=sy && matchMap[j][x0]!=0)return false;
			}
			return true;
		}
		else {
			int sx = x0 > x1 ? x1 : x0;
			int ex = x0 < x1 ? x1 : x0;
			for(int i = sx;i < ex;i++) {
				if(i!=sx && matchMap[y0][i]!=0)return false;
			}
			return true;
		}
	}
	private int getRandInteger(int left, int right) {
		return (int)(Math.random()*(right - left) + left);
	}
}

class Pos {
	private int x,y;
	public Pos() {
		x = y = 0;
	}
	public Pos(int x,int y) {
		setX(x);
		setY(y);
	}
	public int getX() {
		return x;
	}
	public void setX(int x) {
		this.x = x;
	}
	public int getY() {
		return y;
	}
	public void setY(int y) {
		this.y = y;
	}
}

class Btn extends StackPane{
	private Text t;
	private Rectangle r;
	public Btn(String str,double width,double height) {
		t = new Text(str);
		r = new Rectangle(0,0,width,height);
		r.setFill(Color.rgb(200, 250, 150));
		r.setStroke(Color.rgb(0, 0, 0));
		this.getChildren().add(r);
		this.getChildren().add(t);
	}
}