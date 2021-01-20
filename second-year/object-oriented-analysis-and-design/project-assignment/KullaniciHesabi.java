package akilli_cihaz;

public class KullaniciHesabi
{
	private Kullanici kullanici;
        
        public KullaniciHesabi(Kullanici kullanici)
	{
		this.kullanici = kullanici;
	}

//Get ve set metodlarıyla direkt erişimin engellenmesi
	public Kullanici getKullanici() {
		return kullanici;
	}

	public void setKullanici(Kullanici kullanici) {
		this.kullanici = kullanici;
	}

//Kullanıcı adını ekrana yazdıran fonksiyon
    @Override
	public String toString() 
        {
		return "Hoşgeldin " + kullanici.getKullaniciAdi() +"!";
	}
}
