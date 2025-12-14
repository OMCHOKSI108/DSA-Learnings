import 'dart:io';

void main() {
  //String user input
  // print("Enter Name :");
  // String? name = stdin.readLineSync();
  // print("The Entered name is ${name}");

  //Integer USer input
  // print("Enter Roll number : ");
  // int? id = int.parse(stdin.readLineSync()!);
  // print("Entered id is : ${id}");

  //Floating point input
  // print("Enter Float : ");
  // double? f2 = double.parse(stdin.readLineSync()!);
  // print("Entred Floating point is ${f2}");


//     String text1 = 'This is an example of a single-line string.';   
//    String text2 = "This is an example of a single line string using double quotes.";   
//    String text3 = """This is a multiline line   
// string using the triple-quotes.
// This is tutorial on dart strings.
// """;   
//    print(text1);  
//    print(text2);   
//    print(text3);


// String Concatenation 
// String firstName = "Om";
// String lastName = "Choksi";
// print("Using +, Full Name is "+firstName + " " + lastName+".");
// print("Using interpolation, full name is $firstName $lastName.");  



  //  String str = "Sanskruti";
  //  print(str.codeUnits);   //Example of code units
  //  print(str.isEmpty);     //Example of isEmpty
  //  print(str.isNotEmpty);  //Example of isNotEmpty
  //  print("The length of the string is: ${str.length}");   //Example of Length




//    Methods Of String
// toLowerCase(): Converts all characters in this string to lowercase.
// toUpperCase(): Converts all characters in this string to uppercase.
// trim(): Returns the string without any leading and trailing whitespace.
// compareTo(): Compares this object to another.
// replaceAll(): Replaces all substrings that match the specified pattern with a given value.
// split(): Splits the string at matches of the specified delimiter and returns a list of substrings.
// toString(): Returns a string representation of this object.
// substring(): Returns the text from any position you want.
// codeUnitAt(): Returns the 16-bit UTF-16 code unit at the given index.



  //  String address1 = "Sanskruti"; // Here F is capital
  //  String address2 = "Star"; // Here T and A are capital
  //  print("Address 1 in uppercase: ${address1.toUpperCase()}"); 
  //  print("Address 1 in lowercase: ${address1.toLowerCase()}"); 
  //  print("Address 2 in uppercase: ${address2.toUpperCase()}"); 
  //  print("Address 2 in lowercase: ${address2.toLowerCase()}"); 


  // String address1 = " USA"; // Contain space at leading.
  // String address2 = "Japan  "; // Contain space at trailing. 
  // String address3 = "New Delhi"; // Contains space at middle.
  
  // print("Result of address1 trim is ${address1.trim()}");
  // print("Result of address2 trim is ${address2.trim()}");
  // print("Result of address3 trim is ${address3.trim()}");
  // print("Result of address1 trimLeft is ${address1.trimLeft()}");
  // print("Result of address2 trimRight is ${address2.trimRight()}");



  //    String item1 = "Apple"; 
  //  String item2 = "Ant"; 
  //  String item3 = "Basket"; 
   
  //  print("Comparing item 1 with item 2: ${item1.compareTo(item2)}"); 
  //  print("Comparing item 1 with item 3: ${item1.compareTo(item3)}"); 
  //  print("Comparing item 3 with item 2: ${item3.compareTo(item2)}"); 

// String text = "I am a good boy I like milk. Doctor says milk is good for health.";
  
// String newText = text.replaceAll("milk", "water"); 
 
// print("Original Text: $text");
// print("Replaced Text: $newText");  


  // String allNames = "Om, Hari, Dev, het";

  // List<String> listNames = allNames.split(",");
  // print("Value of listName is $listNames");

  // print("List name at 0 index ${listNames[0]}");
  // print("List name at 1 index ${listNames[1]}");
  // print("List name at 2 index ${listNames[2]}");
  // print("List name at 3 index ${listNames[3]}");


//   int number = 30;     
// String result = number.toString(); 
  
// print("Type of number is ${number.runtimeType}");  
// print("Type of result is ${result.runtimeType}");  



  //Example of substring()
  //  String text = "I Like S for speech"; 
  //  print("Print only computer: ${text.substring(7)}"); // from index 6 to the last index 
  //  print("Print only love: ${text.substring(2,6)}");// from index 2 to the 6th index 


  // String input = "sans"; 
  // print("$input Reverse is ${input.split('').reversed.join()}"); 

    String text = "hello world"; 
  print("Capitalized first letter of String: ${text[0].toUpperCase()}${text.substring(1)}"); 
}

