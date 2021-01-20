package odev;

import java.util.Scanner;
import java.io.*;
import java.util.*;
import java.util.regex.Pattern; 

public class Odev {

        public static boolean isValidUrl(String url)
    { 
        String urlRegex = "^(http:\\/\\/www\\.|https:\\/\\/www\\.|http:\\/\\/|https:\\/\\/)?[a-z0-9]+"
                          + "([\\-\\.]{1}[a-z0-9]+)*\\.[a-z]{2,5}(:[0-9]{1,5})?(\\/.*)?$";
                              
        Pattern pat = Pattern.compile(urlRegex); 
        if (url == null) 
            return false; 
        return pat.matcher(url).matches(); 
    } 
        public static boolean isValidMail(String email) 
    { 
        String emailRegex = "^[a-zA-Z0-9_+&*-]+(?:\\."+ 
                            "[a-zA-Z0-9_+&*-]+)*@" + 
                            "(?:[a-zA-Z0-9-]+\\.)+[a-z" + 
                            "A-Z]{2,7}$"; 
                              
        Pattern pat = Pattern.compile(emailRegex); 
        if (email == null) 
            return false; 
        return pat.matcher(email).matches(); 
    } 
    
    public static void main(String[] args) throws FileNotFoundException {
        
       File file = new File("kelime.txt");
       Scanner input = new Scanner(file, "UTF-8");
       Vector<String> vec = new Vector<String>(); 
 
    int sesliHarfSayisi = 0;
    int mailSayisi = 0;
    int urlSayisi = 0;
    int cumleSayisi = 0;
    int kelimeSayisi = 0;
    while (input.hasNext()) {  
      String word  = input.next();
      vec.addElement(word);
      kelimeSayisi++;
    }
    for (int i=0;i<vec.size();i++)
    {
        for (int j=0;j<vec.elementAt(i).length();j++)
        {
           if (vec.elementAt(i).charAt(j)=='a'||vec.elementAt(i).charAt(j)=='A'||vec.elementAt(i).charAt(j)=='e'||vec.elementAt(i).charAt(j)=='E'||
                   vec.elementAt(i).charAt(j)=='ı'||vec.elementAt(i).charAt(j)=='I'||vec.elementAt(i).charAt(j)=='i'||vec.elementAt(i).charAt(j)=='İ'||
                   vec.elementAt(i).charAt(j)=='o'||vec.elementAt(i).charAt(j)=='O'||vec.elementAt(i).charAt(j)=='ö'||vec.elementAt(i).charAt(j)=='Ö'||
                   vec.elementAt(i).charAt(j)=='u'||vec.elementAt(i).charAt(j)=='U'||vec.elementAt(i).charAt(j)=='ü'||vec.elementAt(i).charAt(j)=='Ü')
           {
                sesliHarfSayisi++;
           }
        } 
        if(isValidUrl(vec.elementAt(i))&&(vec.elementAt(i).contains(".net")||vec.elementAt(i).contains(".com.tr")||
                        vec.elementAt(i).contains(".com")||vec.elementAt(i).contains(".org")||vec.elementAt(i).contains(".edu.tr")||
                        vec.elementAt(i).contains(".edu")||vec.elementAt(i).contains(".net.tr")||vec.elementAt(i).contains(".org.tr"))) 
        {
            urlSayisi++;
        }
        else if(isValidMail(vec.elementAt(i))) 
        {
            mailSayisi++;
        }
        else if(vec.elementAt(i).charAt(vec.elementAt(i).length()-1)=='.') 
        {
            cumleSayisi++;
        }
    }
    System.out.println("Sesli Harf Sayısı:" + sesliHarfSayisi);
    System.out.println("Kelime Sayısı:" + kelimeSayisi);
    System.out.println("Cümle Sayısı:" + cumleSayisi);
    System.out.println("E-Mail Sayısı:" + mailSayisi);
    System.out.println("URL Sayısı:" + urlSayisi);
  }   
}
