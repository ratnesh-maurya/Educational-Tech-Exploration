package project;

import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
import java.util.Random;

public class TIC_TAC_TOE extends JFrame implements ActionListener
{
	Random random        = new Random();
	JFrame frame         = new JFrame();
	JLabel textfield     = new JLabel();
	JPanel title_panel   = new JPanel();
	JPanel button_panel  = new JPanel();
	JButton[] buttons    = new JButton[9];
	boolean player1_turn;
	//---------------------------------------------------------------------------------- 
	TIC_TAC_TOE()
	{ 
		frame.setSize(600,700); 
		frame.setVisible(true);
		frame.getContentPane().setLayout(new BorderLayout());
		frame.getContentPane().setBackground(new Color (50, 50, 50));
	    
		textfield.setOpaque(true);

		textfield.setText("Tic-Tac-Toe");
		textfield.setBackground(new Color (25, 25, 25));
		textfield.setForeground(new Color (25, 255, 0));
		textfield.setHorizontalAlignment(JLabel.CENTER);
		textfield.setFont(new Font ("Ink Free",Font.BOLD,75)); 

		title_panel.setLayout (new BorderLayout ());
		title_panel.setBounds(0,0, 800, 100);
		
		button_panel.setLayout(new GridLayout(3,3)); 
		button_panel.setBackground(new Color(150, 150,150));
		
		for(int i=0; i<9; i++)
		{
		     buttons[i] = new JButton(); 
		     button_panel.add(buttons[i]);
		     buttons [i].setFont(new Font("SANTOSH KUMAR",Font.BOLD, 120));
		     buttons[i].setFocusable(false);
		     buttons [i].addActionListener(this);
		}

		title_panel.add(textfield);
		frame.add(title_panel, BorderLayout. NORTH);
		frame.add(button_panel);
		
		FirstTurn();
		Check(); 
	}
//---------------------------------------------------------------------------------- 
   @Override
   public void actionPerformed(ActionEvent e)
   {
     for(int i=0; i<9; i++)
     {
        if(e.getSource() == buttons[i]) 
        {
		    if(player1_turn) 
            {
                if(buttons[i].getText() == "") 
                {
                    buttons[i].setForeground(new Color(255, 0, 0));
                    buttons[i].setText("X");
                    player1_turn = false;
                    textfield.setText("----> Y turn <----");
                    Check();  
                }
            }
		    else if(buttons[i].getText() == "") 
            {
                 buttons[i].setForeground(new Color(0, 0, 255));
                 buttons[i].setText("Y");
                 player1_turn = true;
                 textfield.setText("----> X turn <----");
                 Check();
            }

           
         }
      }
  }   
 
 //---------------------------------------------------------------------------
    public void FirstTurn()
    {
    	try {
    	    Thread.sleep(2000);
    	    } 
    	    catch(InterruptedException e)
    	    { e.printStackTrace(); }
    	
        if(random.nextInt(2) == 0) 
        {
    	   player1_turn=true; 
    	   textfield.setText("----> X turn <----");
        }
        else
        {
     	   player1_turn=false; 
           textfield.setText("----> Y turn <----");
        }
    }   
       
//----------------------------------------------------------------------
     public void Check() 
     { 
    	   
// CHECKING "X" WINNING CONDITION:
         if((buttons[0].getText()=="X") && (buttons[1].getText()=="X") && (buttons[2].getText()=="X"))
         { 
    	     xWins(0,1,2);
         }
         if((buttons[3].getText()=="X") && (buttons[4].getText()=="X") && (buttons[5].getText()=="X"))
         {
             xWins(3,4,5);
         }
         if((buttons[6].getText()=="X") && (buttons[7].getText()=="X") && (buttons[8].getText()=="X"))
         {
             xWins(6,7,8);
         }
         if((buttons[0].getText()=="X") && (buttons[3].getText()=="X") && (buttons[6].getText()=="X"))
         {
             xWins(0,3,6);
         }
         if((buttons[1].getText()=="X") && (buttons[4].getText()=="X") && (buttons[7].getText()=="X"))
         {
             xWins(1,4,7);
         }
        if((buttons[2].getText()=="X") && (buttons[5].getText()=="X") && (buttons[8].getText()=="X")) 
         { 
    	     xWins(2,5,8);
         }
        if((buttons[0].getText()=="X") && (buttons[4].getText()=="X") && (buttons[8].getText()=="X")) 
         { 
    	     xWins(0,4,8);
         }
        if((buttons[2].getText()=="X") && (buttons[4].getText()=="X") && (buttons[6].getText()=="X"))
        { 
    	     xWins(2,4,6);
        }

// CHECKING "Y" WINNING CONDITION:

         if( (buttons[0].getText()=="Y") && (buttons[1].getText()=="Y") && (buttons[2].getText()=="Y"))
         { 
    	     yWins(0,1,2);
         }
         if((buttons[3].getText()=="Y") && (buttons[4].getText()=="Y") && (buttons[5].getText()=="Y"))
         {
             yWins(3,4,5);
         }
         if((buttons[6].getText()=="Y") && (buttons[7].getText()=="Y") && (buttons[8].getText()=="Y"))
         {
             yWins(6,7,8);
         }
         if((buttons[0].getText()=="Y") && (buttons[3].getText()=="Y") && (buttons[6].getText()=="Y"))
         {
             yWins(0,3,6);
         }
         if((buttons[1].getText()=="Y") && (buttons[4].getText()=="Y") && (buttons[7].getText()=="Y"))
         {
             yWins(1,4,7);
         }
        if((buttons[2].getText()=="Y") && (buttons[5].getText()=="Y") && (buttons[8].getText()=="Y")) 
         { 
    	     yWins(2,5,8);
         }
         if((buttons[0].getText()=="Y") && (buttons[4].getText()=="Y") && (buttons[8].getText()=="Y")) 
         { 
    	     yWins(0,4,8);
         }
        if((buttons[2].getText()=="Y") && (buttons[4].getText()=="Y") && (buttons[6].getText()=="Y"))
         { 
    	     yWins(2,4,6);
         }
    }
//--------------------------------------------------------------------------------------------------------------
   public void xWins(int a, int b, int c)
   {
        buttons[a].setBackground(Color.GREEN);
        buttons[b].setBackground(Color.GREEN);
        buttons[c].setBackground(Color.GREEN);
        
        for( int i=0; i<9; i++) 
        {
           buttons[i].setEnabled(false); 
        }
       textfield.setText("X wins");
   } 
   //-----------------------------------------------------------------
   public void yWins(int a, int b, int c) 
   { 
	    buttons[a].setBackground(Color.GREEN);
        buttons[b].setBackground(Color.GREEN); 
        buttons[c].setBackground(Color.GREEN);
        
        for( int i=0; i<9; i++) 
        { 
	       buttons[i].setEnabled(false);
        }
        textfield.setText("Y wins");
   }
//--------------------------------------------------------------------------------------------------------------------
   public static void main(String[] args) 
   {
     new TIC_TAC_TOE();
   }

}




