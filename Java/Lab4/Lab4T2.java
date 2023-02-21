import java.util.List;
import java.util.ArrayList;

abstract class Shape {
	public abstract void draw();
}

class Rectangle extends Shape {
	public void draw() 
	{
		System.out.println("Drawing a rectangle");
	}
}


class Circle extends Shape {
	public void draw() 
	{
		System.out.println("Drawing a circle");
	}
}

class TestShape {
	
	public static void drawShapes(List <? extends Shape> lists) {
		for (Shape sh:lists) 
		{
			sh.draw();
		}
	}
	
	public static void main(String args[]) {
		Rectangle r = new Rectangle(); 
		Circle c = new Circle();

		ArrayList<Shape> list = new ArrayList<>();
		list.add(r);
		list.add(c);
		drawShapes(list);
	}
}