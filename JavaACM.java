import java.util.Scanner;

public class JavaACM {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            while (scanner.hasNext()) {
                int a = scanner.nextInt();
                int b = scanner.nextInt();
                if (a == 0 && b == 0) {
                    break;
                }
                System.out.println(a + b);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}