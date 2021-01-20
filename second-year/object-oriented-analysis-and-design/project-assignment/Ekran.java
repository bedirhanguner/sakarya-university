package akilli_cihaz;

import java.util.Scanner;

public class Ekran implements IEkran 
{

    public void mesajGoruntule(String mesaj) 
    {
        System.out.println(mesaj);
    }
    public int veriAl() 
    {
        Scanner input=new Scanner(System.in);
        return input.nextInt();   
    }
    public String kullaniciAdiAl() 
    {
        Scanner input=new Scanner(System.in);
        return input.nextLine();   
    }
    
    public String sifreAl() 
    {
        Scanner input=new Scanner(System.in);
        return input.nextLine();   
    }   
}
