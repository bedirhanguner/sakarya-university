package akilli_cihaz;

public class Araclar 
{ 
    
    public static void beklet(int milisaniye) 
    {
        try
        {
            Thread.sleep(milisaniye);
        }
        catch(InterruptedException ex)
        {
            Thread.currentThread().interrupt();
        }      
    }  
}
