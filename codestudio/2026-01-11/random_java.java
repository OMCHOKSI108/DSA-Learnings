// Random code
public class RandomCode {
    public static void main(String[] args) {
        int num = 97;
        System.out.println("Random number: " + num);
        for (int i = 0; i < num % 10; i++) {
            System.out.println("Iteration " + i);
        }
    }
}