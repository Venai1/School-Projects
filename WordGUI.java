import java.awt.Container;
import java.awt.GridLayout;
import java.awt.TextArea;
import java.util.Arrays;
import javax.swing.JFrame;
/*
	Imports in order to use Jframe, class extends JFrame allowing it to use methods of JFrame and
	its properties
*/
public class WordGUI extends JFrame{

	
	//Constructor using passed in parameters
    public WordGUI(String title, int height, int width){
    	
    	setSize(width, height);
    	setTitle(title);
    	
    	
    	setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }
    
    public void printToJframe(WordGUI myGUI, String[] wordArray, int size){
    	Container myContentPane = myGUI.getContentPane();
    	TextArea grid[] = new TextArea[6];
    	
    	for(int i = 0; i<6; i++) {
    		grid[i] = new TextArea();
    		myContentPane.add(grid[i]);
    		
    	}
    	
    	
    	
    
    	//Index's for grid array
    	//012
    	//345
    	setLayout(new GridLayout(2,3));


    	
    	
    	for(int i = 0; i<size; i++) {
    		//All words that start with an A or a
    		
    		if(wordArray[i].charAt(0)=='a' || wordArray[i].charAt(0)=='A') {
    			grid[0].append(wordArray[i] + "\n");
    		}
    		
    		//All words that start with an E or e
    		else if(wordArray[i].charAt(0)=='e' || wordArray[i].charAt(0)=='E') {
    			grid[1].append(wordArray[i] + "\n");
    		}
    		
    		//All words that start with an I or i
    		else if(wordArray[i].charAt(0)=='i' || wordArray[i].charAt(0)=='I') {
    			grid[2].append(wordArray[i] + "\n");
    		}
    		
    		//All words that start with an O or o
    		else if(wordArray[i].charAt(0)=='o' || wordArray[i].charAt(0)=='O') {
    			grid[3].append(wordArray[i] + "\n");
    		}
    		
    		//All words that start with an U or u
    		else if(wordArray[i].charAt(0)=='u' || wordArray[i].charAt(0)=='U') {
    			grid[4].append(wordArray[i] + "\n");
    		}
    		
    		//Everything else
    		else grid[5].append(wordArray[i] + "\n");
    	}
    	
    	
    	setVisible(true);

    }
}
