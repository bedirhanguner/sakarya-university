package RastgeleKisiUretPaket;

public class Yas {
    
    public int olustur()
    {
        int altYasAraligi = 0;
        int ustYasAraligi = 101;
        int yasDegeri = (int) ((System.currentTimeMillis() % ustYasAraligi) +altYasAraligi);       
        return yasDegeri;
    }   
}