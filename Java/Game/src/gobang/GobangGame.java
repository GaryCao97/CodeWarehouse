package gobang;

public class GobangGame {
	private int chessboardSize;
	private int[][] chessboard;
	private int whoseTurn; // -1 °× 1 ºÚ

	public GobangGame() {
		this(19);
	}
	public GobangGame(int chessboardSize) {
		this.chessboardSize = chessboardSize;
		chessboard = new int[chessboardSize][chessboardSize];
		for(int i = 0;i < chessboardSize;i++)
			for(int j = 0;j < chessboardSize;j++)
				chessboard[i][j] = 0;
		whoseTurn = 1;
	}
	public boolean canPlace(int i,int j) {
		if(i < 0 || j < 0 || i > chessboardSize || j > chessboardSize)return false;
		if(chessboard[j][i] == 0 && whoseTurn != 0)return true;
		return false;
	}
	public void placeChess(int i,int j) {
		chessboard[j][i] = whoseTurn;
		whoseTurn = whoseTurn > 0 ? -1 : 1;
	}
	public int whoWon(int i,int j) {
		int tmp = chessboard[j][i],num = 1,m;
		//ºáÏßÅĞ¶Ï
		m = 1;
		while((i + m < chessboardSize) && chessboard[j][i + (m++)] == tmp)num++;
		m = 1;
		while((i - m > -1) && chessboard[j][i - (m++)] == tmp)num++;
		if(num >= 5)return tmp;
		//ÊúÏßÅĞ¶Ï
		num = 1;
		m = 1;
		while((j + m < chessboardSize) && chessboard[j + (m++)][i] == tmp)num++;
		m = 1;
		while((j - m > -1) && chessboard[j - (m++)][i] == tmp)num++;
		if(num >= 5)return tmp;
		//×óÉÏÓÒÏÂ
		num = 1;
		m = 1;
		while((i + m < chessboardSize) && (j + m < chessboardSize) && chessboard[j + (m)][i + (m++)] == tmp)num++;
		m = 1;
		while((i - m > -1) && (j - m > -1) && chessboard[j - (m)][i - (m++)] == tmp)num++;
		if(num >= 5)return tmp;
		//×óÏÂÓÒÉÏ
		num = 1;
		m = 1;
		while((i + m < chessboardSize) && (j - m > -1) && chessboard[j - (m)][i + (m++)] == tmp)num++;
		m = 1;
		while((i - m > -1) && (j + m < chessboardSize) && chessboard[j + (m)][i - (m++)] == tmp)num++;
		if(num >= 5)return tmp;
		return 0;
	}
	public int getWhoseTurn() {
		return whoseTurn;
	}
	public void restart() {
		for(int i = 0;i < chessboardSize;i++)
			for(int j = 0;j < chessboardSize;j++)
				chessboard[i][j] = 0;
		whoseTurn = 1;
	}
}
