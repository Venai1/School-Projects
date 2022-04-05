
import org.w3c.dom.Text;
import java.util.StringTokenizer;
import java.awt.Container;
import java.awt.GridLayout;
import java.awt.TextArea;
import java.util.Arrays;
import javax.swing.JFrame;

public class Project1{

public static int inputFromFile(String filename, String[] wordArray){
    
	// create new input function that reads files based off of filename
	TextFileInput in = new TextFileInput(filename);
    //amount of units in array that isn't null.
    int lengthFilled = 0;
    String line = in.readLine();
    
    
    while (line != null ) {
        wordArray[lengthFilled]= line;
        lengthFilled++;
            
        line = in.readLine();
    }// end of first while 
   
    
    //closes the file
    in.close();
    
    
    //return lengthFilled; 
    return lengthFilled;
}  // method inputFromFile


public static void main(String args[]){
	
	//Creates a word array to store the input words
	String[] wordArray = new String[100];
	
	//Inputs words into an array line by line
    int count = inputFromFile("input.txt", wordArray);
    
    
    //Creates a GUI, runs through the constructor which uses passed parameters
    WordGUI myGUI = new WordGUI("Project 1", 600, 300);
    
    //Print to J Frame is a function that organizes the input the prints it to the created 
    //output box.
	myGUI.printToJframe(myGUI, wordArray, count);
	
   
}//main




}//project 1 main class