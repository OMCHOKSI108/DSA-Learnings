void main() {
  // print("Hello World!");
  // var name = "sanskruti";
  // print("hello $name");

  // var firstname = "Om";
  // var lastname = "Choksi";
  // print("my name is $firstname $lastname");

  // int num1 = 10;
  // int num2 = 30;

  // int sum = num1 + num2;
  // int diff = num1 - num2;
  // double div = num2 / num1;
  // int mul = num1 * num2;

  // print("Sum is $sum");
  // print("difference is $diff");
  // print("Division  is $div");
  // print("Multiplication is $mul");

  // const pi = 3.14;
  // pi = 5.23;     // Error: Can't assign to the const variable 'pi'.
  // print("$pi");

  // int num1 = 100; // without decimal point.
  // double num2 = 130.2; // with decimal point.
  // num num3 = 50;
  // num  num4 = 50.4;

  // // For Sum
  // num sum = num1 + num2 + num3 + num4;

  // // Printing Info
  // print("Num 1 is $num1");
  // print("Num 2 is $num2");
  // print("Num 3 is $num3");
  // print("Num 4 is $num4");
  // double var1 = 132.253356363;
  // print("var is $var1");
  // print(var1.toStringAsFixed(2));

  //create multiline string

  //singleQuotes
  //   String S = '''
  //   This is multiline string with singlequotes
  //   This is line text
  //   in this line text you can
  //   see i have written multiline String For my Dear S
  // ''';

  //   //DoubleQuotes
  //   String sans = """
  //   This is Multilined String with Double Quotes
  //   In this text line you will find me to write a paragraph
  //   for varible sans and this is end of this
  //   DoubleQotes
  //   """;

  //   print("Multiline String with single Quotes : $S");
  //   print("Multiline String with Double Quotes : $sans");

  // num price = 10;
  // String withoutRawString = "The value of price is \t $price"; // regular String
  // String withRawString = r"The value of price is \t $price"; // raw String

  // print("Without Raw: $withoutRawString"); // regular result
  // print("With Raw: $withRawString"); // with raw result

  //Convert String To Int In Dart
  // String value = "30";

  // int intvalue = int.parse(value);
  // print("Type of value is ${value.runtimeType}");
  // print("Str value = $value");
  // print("type of INtvalue is ${intvalue.runtimeType}");
  // print("intvalue = $intvalue");

  // Convert String To Double In Dart
  // String vStr = "30.30";
  // print("Type of vStr ${vStr.runtimeType}");
  // print("vStr = $vStr");

  // double dStr = double.parse(vStr);
  // print("Type of dStr ${dStr.runtimeType}");
  // print("dStr = $dStr");

  //Convert Int To String In Dart
  // int one = 1;
  // print("Type of one is ${one.runtimeType}");
  // print("one = $one");
  // String strone = one.toString();
  // print("Type of one is ${strone.runtimeType}");
  // print("Strone = $strone");

  //convert double to int
  // double num1 = 10.01;
  // int num2 = num1.toInt(); // converting double to int

  // print("The value of num1 is $num1. Its type is ${num1.runtimeType}");
  // print("The value of num2 is $num2. Its type is ${num2.runtimeType}");

  // bool isMarried = false;
  // print("Married Status: $isMarried");

  //List in dart

  // List<String> names = ["om", "hari", "dev", "het"];
  // print("Values of name is $names");
  // print("values of names[0] is names[0] is ${names[0]}");  //index 0
  // print("values of names[1] is names[0] is ${names[1]}");  //index 1
  // print("values of names[2] is names[0] is ${names[2]}");  //index 2
  // print("values of names[3] is names[0] is ${names[3]}");  //index 3

  // Set<String> weekday = {
  //   "Sun",
  //   "Mon",
  //   "Tue",
  //   "Wed",
  //   "Thu",
  //   "Fri",
  //   "Sat",
  // }; // all different values
  // print(weekday);

  // Map<String, String> myDetails = {'name': "Om", 'age': "20", 'friend': "S"};
  // print("myName = ${myDetails['name']} \n myAge = ${myDetails['age']} \n myfrd = ${myDetails['friend']}");

  // String value = "a";
  // print(value.runes);

  //  var myVariable = 50; // You can also use int instead of var
  //  myVariable = "Hello"; // this will give error
  //  print(myVariable);

  //Dynamic varibale so we can change values after assigning

  // dynamic myVariable = 50;
  // myVariable = "Hello";
  // print(myVariable);

  //   Types Of Comments
  // Single-Line Comment: For commenting on a single line of code. E.g. // This is a single-line comment.
  // Multi-Line Comment: For commenting on multiple lines of code. E.g. /* This is a multi-line comment. */
  // Documentation Comment: For generating documentation or reference for a project/software package. E.g. 

   // declaring two numbers 
//  int num1=100;
//  int num2=30;
 
//  // performing arithmetic calculation
//  int sum=num1+num2;       // addition
//  int diff=num1-num2;      // subtraction
//  int unaryMinus = -num1;    // unary minus  
//  int mul=num1*num2;       // multiplication
//  double div=num1/num2;    // division
//  int div2 =num1~/num2;     // integer division
//  int mod=num1%num2;       // show remainder
 
// //Printing info 
//  print("The addition is $sum.");
//  print("The subtraction is $diff.");
//  print("The unary minus is $unaryMinus.");
//  print("The multiplication is $mul.");
//  print("The division is $div.");
//  print("The integer division is $div2.");
//  print("The modulus is $mod."); 

// declaring two numbers 
  // int num1=0;
  // int num2=0;
  
  // // performing increment / decrement operator  

  // // pre increment   
  // num2 = ++num1;
  // print("The value of num2 is $num2");

  // // reset value to 0 
  // num1 = 0;
  // num2 = 0;

  // // post increment  
  // num2 =  num1++;
  // print("The value of num2 is $num2");  

  //  double age = 24;
  // age+= 1;  // Here age+=1 means age = age + 1.
  // print("After Addition Age is $age");
  // age-= 1;  //Here age-=1 means age = age - 1.
  // print("After Subtraction Age is $age");
  // age*= 2;  //Here age*=2 means age = age * 2.
  // print("After Multiplication Age is $age");
  // age/= 2;  //Here age/=2 means age = age / 2.
  // print("After Division Age is $age");

//    int num1=10;
//  int num2=5;
//  //printing info
//  print(num1==num2); 
//  print(num1<num2);
//  print(num1>num2);
//  print(num1<=num2);
//  print(num1>=num2);

// int userid = 123;
//     int userpin = 456;

//     // Printing Info
//     print((userid == 123) && (userpin== 456)); // print true
//     print((userid == 1213) && (userpin== 456)); // print false.
//     print((userid == 123) || (userpin== 456)); // print true.
//     print((userid == 1213) || (userpin== 456)); // print true
//     print((userid == 123) != (userpin== 456));//print false


  String value1 = "Dart Tutorial";
  int age = 10;
  
  print(value1 is String);
  print(age is !int);
}
