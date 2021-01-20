package pdp_proje;

import RastgeleKisiUretPaket.IMEINo;
import RastgeleKisiUretPaket.IsimSoyisim;
import RastgeleKisiUretPaket.TCKN;
import RastgeleKisiUretPaket.TelefonNo;
import RastgeleKisiUretPaket.Yas;

import java.io.IOException;

public class Kisi 
{
    IsimSoyisim isimSoyisim = new IsimSoyisim();
    Yas yas = new Yas();
    TCKN tckn = new TCKN();
    TelefonNo telefonNo = new TelefonNo();
    IMEINo imeiNo = new IMEINo();
    
    
    public Kisi()
    {               
    }
  public String getAdSoyad() throws IOException {
    return isimSoyisim.olustur();
  } 
  public void setAdSoyad(){}
  
  public int getYas() {
    return yas.olustur();
  }  
  public void setYas(){}
  
  public String getTCKN() {
    return tckn.olustur();
  }
  public void setTCKN() {}
  
  public String getTelefonNo() {
    return telefonNo.olustur();
  }
  public void setTelefonNo(){}
  
  public String getIMEINo() {
    return imeiNo.olustur();
  }
  public void setIMEINo(){}   
}
