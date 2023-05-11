import java.util.Scanner;

class Test {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Skriv in första talet: ");
        int tal1 = input.nextInt();
        System.out.print("Skriv in andra talet: ");
        int tal2 = input.nextInt();

        System.out.println("Skriv in arbetsläge (1 = +, 2 = -, 3 = *, 4 = /)");
        int arbetsläge = input.nextInt();
        switch(arbetsläge) {
            case 1: System.out.println(tal1+tal2); break;
            case 2: System.out.println(tal1-tal2); break;
            case 3: System.out.println(tal1*tal2); break;
            case 4: System.out.println(tal1/tal2); break;
            default: System.out.println("Det läget finns inte!"); break;
        }
    }
};