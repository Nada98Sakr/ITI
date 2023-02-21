
package animationball;


import javax.swing.ImageIcon;
import java.awt.BorderLayout;
import java.awt.Toolkit;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JFrame;
import javax.swing.JLabel;

public class AnimationBall extends JFrame implements Runnable
{
    Thread th;
    ImageIcon i = new ImageIcon(Toolkit.getDefaultToolkit().getImage("Ball1-new1.jpg"));
    JLabel label = new JLabel(i);
    
    int x = 0;
    int y = 0;
    
    public AnimationBall()
    {
        this.setLayout(null);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setTitle("Ball Movement");
        label.setHorizontalAlignment(JLabel.LEFT);
        label.setBounds(x, y, i.getIconWidth(), i.getIconWidth());
        this.add(label,BorderLayout.CENTER);
        th = new Thread(this);
        th.start();
    }
    public static void main(String []args)
    {
        AnimationBall app=new AnimationBall ();
        app.setBounds(app.x, app.y, 600, 400);
        app.setVisible(true);
    }
    public void run()
    {
        int xDir = 1;
        int yDir = 1;
        
        while(true)
        {
            x += xDir;
            y += yDir;
            
            
            
            if( x >= (getWidth() - i.getIconWidth()))
            {
                xDir = -xDir;
            }
           
            if( y >= this.getHeight() - i.getIconHeight())
            {
                yDir = -yDir;
            }
            
            if( x <= 0 )
            {
                xDir = -xDir;
                x = 0;
            }
            
            if( y <= 0 )
            {
                yDir = -yDir;
                y = 0;
            }
            
            label.setLocation(x,y);
        try {
            Thread.sleep(10);
         } 
         catch (InterruptedException ex) {
            Logger.getLogger(AnimationBall.class.getName()).log(Level.SEVERE, null, ex);
         }
        }
    }

    private void add(ImageIcon JavaImage, String LINE_START) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }
}