package pdp_proje;
import java.io.IOException;
import java.util.Scanner;

public class RastgeleKisi 
{
    public static void main(String[] args) throws IOException
    {
        String tercih = "";
        Scanner scan = new Scanner(System.in);
        do
        {
            System.out.println("Yapmak istediginiz islemi seciniz: \n1)Rastgele Kisi Olustur: \n2)Olusturulan Kisiyi Kontrol Et: \n3)Cikis: ");
            Scanner islem = new Scanner(System.in);
            int secim = islem.nextInt();
            if(secim == 1)
            {
                rastgeleKisiOlustur();
            }
            if (secim == 2)
            {
                uretilmisDosyayıKontrolEt();
            }
            if (secim == 3)
            {
                System.exit(0);
            } 
            
            System.out.println("Baska bir islem yapmak istiyor musunuz? (e/h)");
            tercih=scan.next();
        }while(tercih.equalsIgnoreCase("e"));
    }
    static void rastgeleKisiOlustur() throws IOException
    {
        Kisi yeniKisi = new Kisi();
        
        System.out.print(yeniKisi.getTCKN() + " ");
        System.out.print(yeniKisi.getAdSoyad() + " ");
        System.out.print(yeniKisi.getYas() + " ");   
        System.out.print(yeniKisi.getTelefonNo() + " ");
        System.out.print("(" + yeniKisi.getIMEINo() + ")\n");
        
    } 
    static void uretilmisDosyayıKontrolEt() throws IOException
    {     
        Kisi kontrolKisi = new Kisi();

        String kontrolEdilecekTC =kontrolKisi.getTCKN();
        System.out.println("Kisi icin olusturulmus rastgele TC kimlik numarası: "+ kontrolEdilecekTC);       
        String diziTC = kontrolEdilecekTC;
        int[] tcDizi = new int[diziTC.length()]; 

        for (int i = 0; i < diziTC.length(); i++) { 
            tcDizi[i] = Character.digit(diziTC.charAt(i), 10);
        } 
        if(tcDizi[0] == 0)
        {
            System.out.println("Kisi icin olusturulan rastgele TC kimlik numarası GECERSIZDIR.");  
        }
        if (((tcDizi[0] + tcDizi[2] + tcDizi[4] + tcDizi[6] + tcDizi[8]) * 7 + (tcDizi[1] + tcDizi[3] + tcDizi[5] + tcDizi[7]) * 9) % 10 != tcDizi[9])
        {
            System.out.println("Kisi icin olusturulan rastgele TC kimlik numarası GECERSIZDIR.");     
        }
        if(( tcDizi[0] + tcDizi[1] + tcDizi[2] + tcDizi[3] + tcDizi[4] + tcDizi[5] + tcDizi[6] + tcDizi[7] + tcDizi[8] + tcDizi[9])%10 != tcDizi[10])
        {
            System.out.println("Kisi icin olusturulan rastgele TC kimlik numarası GECERSIZDIR.");     
        }
        else
        {
            System.out.println("Kisi icin olusturulan rastgele TC kimlik numarası GECERLIDIR.");  
        }
              
        String kontrolEdilecekIMEI = kontrolKisi.getIMEINo();
        System.out.println("\nKisi icin olusturulmus rastgele IMEI numarası: "+ kontrolEdilecekIMEI);       
        String diziIMEI = kontrolEdilecekIMEI;
        int[] imeiDizi = new int[diziIMEI.length()]; 
        int tekBasamakToplami = 0;
        int ciftBasamakToplami = 0;
        int genelToplam;
        int bolum;
        
        for (int i = 0; i < diziIMEI.length(); i++) { 
            imeiDizi[i] = Character.digit(diziIMEI.charAt(i), 10);
        }
        for (int i = 0; i <14; i++)
        {
           if( i%2 == 0)
               tekBasamakToplami = tekBasamakToplami + imeiDizi[i];
        }        
        for (int i = 0; i <14; i++)
        {
            if( i%2 == 1)
                if(imeiDizi[i]*2 >=10)
                {
                    ciftBasamakToplami  = ciftBasamakToplami + ((imeiDizi[i]*2)%10)+1;
                }
                else
                {
                    ciftBasamakToplami = ciftBasamakToplami + imeiDizi[i]*2;
                }
        }
        genelToplam = tekBasamakToplami + ciftBasamakToplami;
        bolum = genelToplam / 10;       
        if(genelToplam %10 == 0)
        {
            if(imeiDizi[14] != 0)
            {
                System.out.println("Kisi icin olusturulan rastgele IMEI numarası GECERSIZDIR."); 
            }  
            else
            {
                System.out.println("Kisi icin olusturulan rastgele IMEI numarası GECERLIDIR."); 
            }
        }  
        else
            if(imeiDizi[14] != (10*(bolum + 1)) - genelToplam)
            {
                System.out.println("Kisi icin olusturulan rastgele IMEI numarası GECERSIZDIR."); 
            }
            else
            {
                System.out.println("Kisi icin olusturulan rastgele IMEI numarası GECERLIDIR."); 
            }
    }
}