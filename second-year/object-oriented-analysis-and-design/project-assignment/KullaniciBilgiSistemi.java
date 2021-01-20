package akilli_cihaz;

public class KullaniciBilgiSistemi implements IKullaniciBilgiSistemi 
{
       
    public void kullaniciDogrula(String kullaniciAdi, String sifre) 
    {

        System.out.println("Sistem kullanıcıyı doğruluyor...");
        Araclar.beklet(1000);
        KullaniciVeritabani kullaniciVeriTabani = new KullaniciVeritabani();

//Girilen değerlerin veritabanına gönderilip aranması
        kullaniciVeriTabani.ara(kullaniciAdi, sifre);
    }
}
