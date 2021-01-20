using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace B171210036_1D_PROJE
{
    class Ordek :Kumes
    {
        public Ordek(int can, int yumurtaSayisi, int yumurtaFiyati, int canAzalmaMiktari, int uretimSikligi) : base(can, yumurtaSayisi, yumurtaFiyati, canAzalmaMiktari, uretimSikligi)
        {
            this.can = can;
            this.yumurtaSayisi = yumurtaSayisi;
            this.yumurtaFiyati = yumurtaFiyati;
            this.canAzalmaMiktari = canAzalmaMiktari;
            this.uretimSikligi = uretimSikligi;
        }
    }
}
