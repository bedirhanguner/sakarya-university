package akilli_cihaz;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

public class KullaniciVeritabani 
{
    private KullaniciHesabi kullaniciHesabi;
 
    private Connection baglan()
    {

        Connection conn=null;

        try 
        {
            conn = DriverManager.getConnection("jdbc:postgresql://localhost:5432/KAYITLAR",
                    "postgres", "password");
            if (conn != null)
            {
                System.out.println("Veritabanı bağlandı!");
                Araclar.beklet(1000);
            }
            else
                System.out.println("Bağlantı girişimi başarısız!");
        } catch (Exception e) 
        {
            e.printStackTrace();
        }
        return conn;
    }
   
    public Kullanici ara(String kullaniciAdi, String sifre)
    {
        System.out.println("Kayıtlı kullanıcı aranıyor...");
        Kullanici kullanici = null;

        String kullaniciAdiAra = "SELECT *  FROM \"KULLANICI\" WHERE \"kullaniciAdi\"="+kullaniciAdi;
        String sifreAra = "SELECT *  FROM \"KULLANICI\" WHERE \"sifre\"="+sifre;
                
        Connection conn=this.baglan();
        try
        {
            Statement stmt = conn.createStatement();
            ResultSet rsAd = stmt.executeQuery(kullaniciAdiAra);
            ResultSet rsSifre = stmt.executeQuery(sifreAra);

            conn.close();

            String _kullaniciAdi;
            String _sifre;

            _kullaniciAdi  = rsAd.getString("kullaniciAdi");
            _sifre = rsSifre.getString("sifre");

            kullanici = new Kullanici(_kullaniciAdi, _sifre);
            kullaniciHesabi= new KullaniciHesabi(kullanici);
            
            rsAd.close();
            rsSifre.close();
            stmt.close();
        }
        
        catch (SQLException e) 
        {
            e.printStackTrace();
        }

        return kullanici;
    }   
}
