/***************************************************

  Name: Tsubasa Matsumoto
  Date: 2.22.2017
  Homework #7-8
  
  Program name:        HexConversion
  Program description: Accepts hexadecimal numbers as input and converts each number to binary
                       and to the decimal equivalent.
                       Valid input examples: F00D, 000a, 1010, FFFF, Goodbye, GOODBYE
                       Enter GOODBYE (case insensitive) to exit the program.
  
****************************************************/

package hw8;

import java.util.Scanner;

public class HexConversion {

  public static void main(String[] args) {
    	
    // Maximum length of input string
    final byte INPUT_LENGTH = 4;
    	
    String userInput = "";                   // Initialize to null string
    Scanner input = new Scanner(System.in);

    // Process the inputs until GOODBYE is entered
    do {
      // Input a 4 digit hex number
      System.out.print("\nEnter a hexadecimal string, or enter GOODBYE to quit:  ");
      userInput = input.next().toUpperCase();
		  
      // Process the input
      switch (userInput) {
		  
        case "GOODBYE": break;
            
        default:        if (isValidHex(userInput, INPUT_LENGTH)) {
                          // The input is a valid hexadecimal string
				
                          // Convert the hexadecimal string to binary and print the binary number as a string
                          String binVal = hex2Bin(userInput, INPUT_LENGTH);
		                      
                          // Convert the hexadecimal string to decimal and print the decimal number
                          long decVal = hex2Dec(userInput, INPUT_LENGTH);
                          System.out.printf("      0x%s = %s in binary = %d in decimal (unsigned).\n", userInput, binVal, decVal);
                        }
			
                        else {
                          // String is either the wrong length or is not a valid hexadecimal string
                          System.out.printf("      The string %s is not a valid input.\n", userInput);
                        }
                        break;
        }
    } while (!userInput.equalsIgnoreCase("GOODBYE"));
		
    // Exit the program
    System.out.println("\nGoodbye!");
    input.close();
  }
 
  // Method to validate the input
  public static boolean isValidHex(String userIn, byte inputLen) {
    boolean isValid = false;
    	
    // If length of the input string is equal to inputLen, continue with validation,
    // otherwise return false
    if (userIn.length() == inputLen) {
        
      // The length is correct, now check that the characters are legal hexadecimal digits
      for (int i = 0; i < inputLen; i++) {
        char thisChar = userIn.charAt(i);
          
        // Is the character a decimal digit (0..9)? If so, advance to the next character
        if (Character.isDigit(thisChar)) {
          isValid = true;
        }
	        
        else {	
          // Character is not a decimal digit (0..9), is it a valid hexadecimal digit (A..F)?
        //char ch = Character.toUpperCase(thisChar);
          if(thisChar == 'A' || thisChar == 'B' || thisChar == 'C' || thisChar == 'D' || thisChar == 'E' || thisChar == 'F'){
        	  	isValid = true; // Return true if the string is a valid hexadecimal string, false otherwise
          }
        
          }
        }
      }
	return isValid;
    }
        
 

  

    
  // Method to convert the hex number to a binary string
  public static String hex2Bin(String hexString, byte inputLen) {
    String binString = "";     // Initialize binString to null string 
    
    // Convert each hexadecimal digit to its binary equivalent
    for (int i = 0; i < inputLen; i++) {
      char thisChar = hexString.charAt(i);
      System.out.println(thisChar);
	        
      // Convert hexString to a binary string, e.g. F00D = 1111000000001101
      switch(thisChar){
      case '1': thisChar = '0';
      binString = "0000";
      break;
      case '2': thisChar = '1';
      binString += "0001";
      break;
      case '3': thisChar = '2';
      binString = binString +"0010";
      break;
      case '4': thisChar = '3';
      binString = binString +"0011";
      break;
      case '5': thisChar = '4';
      binString = binString +"0100";
      break;
      case '6': thisChar = '5';
      binString = binString +"0101";
      break;
      case '7': thisChar = '6';
      binString = binString +"0110";
      break;
      case '8': thisChar = '7';
      binString = binString +"0111";
      break;
      case '9': thisChar = '8';
      binString = binString +"1000";
      break;
      case '10': thisChar = '9';
      binString = binString +"1001";
      break;
      case '11': thisChar = 'A';
      binString = binString +"1010";
      break;
      case '12': thisChar = 'B';
      binString = binString +"1011";
      break;
      case '13': thisChar = 'C';
      binString = binString +"1100";
      break;
      case '14': thisChar = 'D';
      binString = binString +"1101";
      break;
      case '15': thisChar = 'E';
      binString = binString +"1110";
      break;
      case '16': thisChar = 'F';
      binString = binString +"1111";
      break;
    		  
      }
      
    }
    
    System.out.println(binString);
	return binString;
	
    
    

  }
    
  // Method to convert the hex number to decimal number
  public static long hex2Dec(String hexString, byte inputLen) {
	    long binInt = 0;     // Initialize binString to null string
    	
	    // Convert each hexadecimal digit to its decimal equivalent
	    for (int i = 0; i < inputLen; i++) {
	      char thisChar = hexString.charAt(i);
		        
	      // Convert hexString to decimal
	      switch(thisChar){
	      case 1: thisChar = '0';
	      binInt = binInt + 0;
	      case 2: thisChar = '1';
	      binInt = binInt + 1;
	      case 3: thisChar = '2';
	      binInt = binInt + 2;
	      case 4: thisChar = '3';
	      binInt = binInt + 3;
	      case 5: thisChar = '4';
	      binInt = binInt + 4;
	      case 6: thisChar = '5';
	      binInt = binInt + 5;
	      case 7: thisChar = '6';
	      binInt = binInt + 6;
	      case 8: thisChar = '7';
	      binInt = binInt + 7;
	      case 9: thisChar = '8';
	      binInt = binInt + 8;
	      case 10: thisChar = '9';
	      binInt = binInt + 9;
	      case 11: thisChar = 'A';
	      binInt = binInt + 10;
	      case 12: thisChar = 'B';
	      binInt = binInt + 11;
	      case 13: thisChar = 'C';
	      binInt = binInt + 12;
	      case 14: thisChar = 'D';
	      binInt = binInt + 13;
	      case 15: thisChar = 'E';
	      binInt = binInt + 14;
	      case 16: thisChar = 'F';
	      binInt = binInt + 15;
	    		  
	      }
	      
	    }
		
	    return binInt;
	    

	  }
}
