package akilli_cihaz;


import java.util.Random;

public class SicaklikAlgilayici implements ISicaklikAlgilayici
{

    private int olculenSicaklik;
    Random random = new Random();
   
    public int sicaklikOlc()
    {
        olculenSicaklik  = -100 + random.nextInt(200);
        return olculenSicaklik;
    }
}
