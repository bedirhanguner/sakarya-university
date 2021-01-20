package akilli_cihaz;

public class AgArayuzu implements IAgArayuzu 
{
   
    Eyleyici eyleyici = new Eyleyici();
    SicaklikAlgilayici sicaklikAlgilayici = new SicaklikAlgilayici();
 
    public void sogutucuActir()
    {
        System.out.println("Eyleyiciye bağlanılıyor...");
        Araclar.beklet(1000);
        
        eyleyiciyiBaglandiMi(true);
        eyleyici.sogutucuAc();       
    }
  
    public void sogutucuKapattir()
    {
        System.out.println("Eyleyiciye bağlanılıyor...");
        Araclar.beklet(1000);
        
        eyleyiciyiBaglandiMi(true);
        eyleyici.sogutucuKapat();
    }
  
    public void sicaklikOlctur()
    {
        System.out.println("Sıcaklık algılayıcıya bağlanılıyor...");
        Araclar.beklet(1000);
        
        sicaklikAlgilayiciyaBaglandiMi(true);
        System.out.println("Yeni sicaklık " + sicaklikAlgilayici.sicaklikOlc() + " olarak olculdu.\n");
    }
 
    public boolean eyleyiciyiBaglandiMi(boolean baglanti)
    {
        if(baglanti == true)
        {
            System.out.println("Eyleyiciye Bağlandı...");
            return true;
        }
        
        else 
        {
            System.out.println("Eyleyiciye Bağlanılamadı...");
            return false;
        }
    }
 
    public boolean sicaklikAlgilayiciyaBaglandiMi(boolean baglanti)
    {
        if(baglanti == true)
        {
            System.out.println("Sıcaklık Algılayıcıya Bağlandı...");
            return true;
        }
        
        else 
        {
            System.out.println("Sıcaklık Algılayıcıya Bağlanılamadı...");
            return false;
        }
    }
}
