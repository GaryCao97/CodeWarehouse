package AfterClass;

public class MyRectangle2D {
	private double x, y;
	private double width, height;
	public MyRectangle2D() {
		this(0,0,1,1);
	}
	public MyRectangle2D(double x, double y, double width, double height) {
		this.x = x;
		this.y = y;
		this.width = width;
		this.height = height;
	}
	public double getX() {
		return x;
	}
	public double getY() {
		return y;
	}
	public double getWidth() {
		return width;
	}
	public double getHeight() {
		return height;
	}
	public void setX(double x) {
		this.x = x;
	}
	public void setY(double y) {
		this.y = y;
	}
	public void setWidth(double width) {
		this.width = width;
	}
	public void setHeight(double height) {
		this.height = height;
	}
	public double getAreac() {
		return width * height;
	}
	public double getPerimeter() {
		return 2 * (width + height);
	}
	public boolean contains(double x, double y) {
		if(x < this.x - 0.5 * width)
			return false;
		else if(x > this.x + 0.5 * width)
			return false;
		else if(y < this.y - 0.5 * height)
			return false;
		else if(y > this.y + 0.5 * height)
			return false;
		return true;
	}
	public boolean contains(MyRectangle2D r) {
		if((r.x - 0.5 * r.width) < (x - 0.5 * width))
			return false;
		else if((r.x + 0.5 * r.width) > (x + 0.5 * width))
			return false;
		else if((r.y - 0.5 * r.height) < (y - 0.5 * height))
			return false;
		else if((r.y + 0.5 * r.height) > (y + 0.5 * height))
			return false;
		return true;
	}
	public boolean overlaps(MyRectangle2D r) {
		if((r.x + 0.5 * r.width) < (x - 0.5 * width))
			return false;
		else if((r.x - 0.5 * r.width) > (x + 0.5 * width))
			return false;
		else if((r.y + 0.5 * r.height) < (y - 0.5 * height))
			return false;
		else if((r.y - 0.5 * r.height) > (y + 0.5 * height))
			return false;
		else if(contains(r))
			return false;
		return true;
	}
}
