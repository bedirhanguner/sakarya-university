package akilli_cihaz;

public class MerkeziIslemBirimi
{
    
	private IEkran ekran;
        private IAgArayuzu agArayuzu;
	private IEyleyici eyleyici;
	private ISicaklikAlgilayici sicaklikAlgilayici;

	private static final int SICAKLIK_GORUNTULE = 1;
	private static final int SOGUTUCU_AC = 2;
	private static final int SOGUTUCU_KAPAT = 3;
        private static final int CIKIS = 4;

	public MerkeziIslemBirimi() 
	{

            this.ekran = new Ekran();
            this.agArayuzu = new AgArayuzu();
            this.eyleyici = (IEyleyici) new Eyleyici();
            this.sicaklikAlgilayici = (ISicaklikAlgilayici) new SicaklikAlgilayici();
	}

	public void baslat() 
        {
          
            ekran.mesajGoruntule("Lütfen kullanıcı adı ve şifrenizle oturum açınız.");

            ekran.mesajGoruntule("Kullanıcı Adınız: ");
            String girilenKullaniciAdi = ekran.kullaniciAdiAl();
            ekran.mesajGoruntule("Sifreniz: ");
            String girilenSifre = ekran.sifreAl();
       
            Kullanici kullanici = new Kullanici(girilenKullaniciAdi, girilenSifre);

            KullaniciHesabi kullaniciHesabi = new KullaniciHesabi(kullanici);
            
            IKullaniciBilgiSistemi kullaniciBilgiSistemi = new KullaniciBilgiSistemi();
            
            kullaniciBilgiSistemi.kullaniciDogrula(kullanici.getKullaniciAdi(), kullanici.getSifre());

            ekran.mesajGoruntule(kullaniciHesabi.toString());
            islemSecimi();
        }      

        private int anaMenuyuGoster()
	{
            ekran.mesajGoruntule("******************************************");
            ekran.mesajGoruntule("Ana Menu");
            ekran.mesajGoruntule("1-Sicaklik Goruntule");
            ekran.mesajGoruntule("2-Sogutucu Ac");
            ekran.mesajGoruntule("3-Sogutucu Kapat");
            ekran.mesajGoruntule("4-Cikis");
            ekran.mesajGoruntule("******************************************");
            ekran.mesajGoruntule("Seciminiz:");

            return ekran.veriAl();
	}
        
	private void islemSecimi()
        {
            int secim;
            do
            {
                secim=anaMenuyuGoster();
                switch (secim) 
                {
                    case SICAKLIK_GORUNTULE:
                            agArayuzu.sicaklikOlctur();
                            break;
                            
                    case SOGUTUCU_AC:
                            agArayuzu.sogutucuActir();
                            break;

                    case SOGUTUCU_KAPAT:
                            agArayuzu.sogutucuKapattir();
                            break;

                    case CIKIS:
                            ekran.mesajGoruntule("Çıkılıyor...");
                            Araclar.beklet(1000);
                            System.exit(0);
                            break;

                    default:
                            ekran.mesajGoruntule("1-4 arasında bir sayı girmelisiniz");
                }
            }while(secim!=4);
	}
}
