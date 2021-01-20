package RastgeleKisiUretPaket;

import java.util.Random;

public class TelefonNo {
    public String olustur()
    {
        int[] telefonNumarasi = new int[12];
        String telefonNODizi = "";
        
        Random random = new Random();
 
        telefonNumarasi[0] = 9;
        telefonNumarasi[1] = 0;
        telefonNumarasi[2] = 5;
        telefonNumarasi[3] = 0 + random.nextInt(6);
 
        for (int i = 4; i < 12; i++) 
        {
            telefonNumarasi[i]= 0 + random.nextInt(10);    
        }
        
        for (int i = 0; i < 12; i++) 
        {
            telefonNODizi += telefonNumarasi[i];  
        }
        return telefonNODizi;
    }
}