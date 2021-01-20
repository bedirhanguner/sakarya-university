package RastgeleKisiUretPaket;

import java.util.Random;

public class IMEINo {
    public String olustur()
    {
        int[] IMEINumarasi = new int[15];
        String IMEIDizi ="";
        int tekBasamakToplami = 0;
        int ciftBasamakToplami = 0;
        int genelToplam;
        int bolum;
        
        Random random = new Random();
  
        for (int i = 0; i < 14; i++) 
        {
            IMEINumarasi[i]= 0 + random.nextInt(10);    
        }        
        for (int i = 0; i <14; i++)
        {
           if( i%2 == 0)
               tekBasamakToplami = tekBasamakToplami + IMEINumarasi[i];
        }
       
        for (int i = 0; i <14; i++)
        {
            if( i%2 == 1)
                if(IMEINumarasi[i]*2 >=10)
                {
                    ciftBasamakToplami  = ciftBasamakToplami + ((IMEINumarasi[i]*2)%10)+1;
                }                
                else
                {
                    ciftBasamakToplami = ciftBasamakToplami + IMEINumarasi[i]*2;
                }
        }      
        genelToplam = tekBasamakToplami + ciftBasamakToplami;       
        bolum = genelToplam / 10;
      
        if(genelToplam%10 == 0)
        {
            IMEINumarasi[14] = 0;
        }
        else
        {
            IMEINumarasi[14] = (10*(bolum + 1)) - genelToplam;
        }
		
        for (int i = 0; i < 15; i++) 
        {
            IMEIDizi += IMEINumarasi[i];  
        }     
        return IMEIDizi;
    }
}