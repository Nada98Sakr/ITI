package javawordapp;

import java.awt.BorderLayout;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JFrame;
import javax.swing.JLabel;

public class JavaWordApp extends JFrame implements Runnable
{
    Thread th;
    JLabel JavaLabel = new JLabel("java world");
    
    int x = 5;
    
    public JavaWordApp()
    {
        this.setLayout(null);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setTitle("Java Movement");
        JavaLabel.setHorizontalAlignment(JLabel.CENTER);
        JavaLabel.setBounds(x, 200, 100, 100);
        JavaLabel.setText("Java Word");
        this.add(JavaLabel,BorderLayout.LINE_START);
        th = new Thread(this);
        th.start();
    }
    public static void main(String []args)
    {
        JavaWordApp app=new JavaWordApp ();
        app.setBounds(app.x, 50, 600, 400);
        app.setVisible(true);
    }
    public void run()
    {
        while(true)
        {
            
            x += 8; 
            JavaLabel.setLocation(x% getSize().width,40);
     
            try {
                Thread.sleep(100);
             } 
             catch (InterruptedException ex) {
                Logger.getLogger(JavaWordApp.class.getName()).log(Level.SEVERE, null, ex);
             }
        }
   }
}