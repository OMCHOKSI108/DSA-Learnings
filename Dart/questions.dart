// Dart Practice Questions Solutions
import 'dart:io';

void main() {
  // 1. Program to print name
  print('\n1. Printing name:');
  print('Sanskruti');

  // 2. Print name with single and double quotes
  print('\n2. Printing with quotes:');
  print('Hello I am "Sanskruti"');
  print("Hello I'am \"Sanskruti\"");

  // 3. Declare constant type of int
  print('\n3. Constant integer:');
  const int number = 7;
  print('Constant number: $number');

  // 4. Calculate Simple Interest
  print('\n4. Simple Interest Calculator:');
  print('Enter Principal amount:');
  double principal = double.parse(stdin.readLineSync()!);
  print('Enter Time (in years):');
  double time = double.parse(stdin.readLineSync()!);
  print('Enter Rate of interest:');
  double rate = double.parse(stdin.readLineSync()!);

  double simpleInterest = (principal * time * rate) / 100;
  print('Simple Interest: $simpleInterest');

  // 5. Square of a number
  print('\n5. Square Calculator:');
  print('Enter a number:');
  double num = double.parse(stdin.readLineSync()!);
  print('Square of $num is: ${num * num}');

  // 6. Full name from first and last name
  print('\n6. Full Name Generator:');
  print('Enter first name:');
  String firstName = stdin.readLineSync()!;
  print('Enter last name:');
  String lastName = stdin.readLineSync()!;
  print('Full Name: $firstName $lastName');

  // 7. Quotient and remainder
  print('\n7. Quotient and Remainder:');
  print('Enter first number:');
  int num1 = int.parse(stdin.readLineSync()!);
  print('Enter second number:');
  int num2 = int.parse(stdin.readLineSync()!);

  int quotient = num1 ~/ num2;
  int remainder = num1 % num2;
  print('Quotient: $quotient');
  print('Remainder: $remainder');

  // 8. Swap two numbers
  print('\n8. Number Swapping:');
  print('Enter first number:');
  int a = int.parse(stdin.readLineSync()!);
  print('Enter second number:');
  int b = int.parse(stdin.readLineSync()!);

  print('Before swap: a = $a, b = $b');
  int temp = a;
  a = b;
  b = temp;
  print('After swap: a = $a, b = $b');

  // 9. Remove whitespaces from string
  print('\n9. Remove Whitespaces:');
  String textWithSpaces = "  Hello   World  with   spaces   ";
  String textWithoutSpaces = textWithSpaces.replaceAll(' ', '');
  print('Original text: "$textWithSpaces"');
  print('Text without spaces: "$textWithoutSpaces"');

  // 10. Convert String to int
  print('\n10. String to Integer:');
  String strNumber = "123";
  int convertedNumber = int.parse(strNumber);
  print('String: $strNumber');
  print('Converted to integer: $convertedNumber');

  // 11. Split bill calculator
  print('\n11. Bill Splitter:');
  print('Enter total bill amount:');
  double billAmount = double.parse(stdin.readLineSync()!);
  print('Enter number of people:');
  int numberOfPeople = int.parse(stdin.readLineSync()!);

  double splitAmount = billAmount / numberOfPeople;
  print('Each person should pay: \$${splitAmount.toStringAsFixed(2)}');

  // 12. Time to reach office calculator
  print('\n12. Travel Time Calculator:');
  double distance = 25; // km
  double speed = 40; // km/h

  double timeInHours = distance / speed;
  double timeInMinutes = timeInHours * 60;
  print(
    'Time taken to reach office: ${timeInMinutes.toStringAsFixed(2)} minutes',
  );
}
