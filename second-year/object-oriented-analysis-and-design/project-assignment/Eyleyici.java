package akilli_cihaz;

public class Eyleyici implements IEyleyici
{

    public void sogutucuAc() 
    {     
        System.out.println("Sogutucu Aciliyor...");
        Araclar.beklet(1000);
        
        System.out.println("Sogutucu Acildi.\n");
        Araclar.beklet(1000);
    }
    
    public void sogutucuKapat() 
    {
        System.out.println("Sogutucu Kapatiliyor...");
        Araclar.beklet(1000); 
        
        System.out.println("Sogutucu Kapatildi.\n");
        Araclar.beklet(1000);
    }
}
