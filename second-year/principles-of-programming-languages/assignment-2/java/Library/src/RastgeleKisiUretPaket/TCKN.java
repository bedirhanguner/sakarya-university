package RastgeleKisiUretPaket;

import java.util.Random;

public class TCKN {
    
    public String olustur()
    {
        int[] TCKN = new int[11];
        String TCKNDizi = "";
        
        Random random = new Random();      
        TCKN[0] = 1 + random.nextInt(9);
        for (int i = 1; i < 9; i++) 
        {
            TCKN[i]= 0 + random.nextInt(10);    
        }
        TCKN[9] = (7*(TCKN[0] + TCKN[2] + TCKN[4] + TCKN[6] +  TCKN[8]) + 9*( TCKN[1] + TCKN[3] + TCKN[5] + TCKN[7]))%10;
		
        TCKN[10] = ( TCKN[0] + TCKN[1] + TCKN[2] + TCKN[3] + TCKN[4] + TCKN[5] + TCKN[6] + TCKN[7] + TCKN[8] + TCKN[9])%10;
  
        for (int i = 0; i < 11; i++) 
            TCKNDizi += TCKN[i];   
        
        return TCKNDizi;
    }
}