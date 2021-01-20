using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace B171210036_1D_PROJE
{
    class Keci :Ahir
    {
        public Keci(int can, int sutLitresi, int sutFiyati, int canAzalmaMiktari, int uretimSikligi) : base(can, sutLitresi, sutFiyati, canAzalmaMiktari, uretimSikligi)
        {
            this.can = can;
            this.sutLitresi = sutLitresi;
            this.sutFiyati = sutFiyati;
            this.canAzalmaMiktari = canAzalmaMiktari;
            this.uretimSikligi = uretimSikligi;
        }
    }
}
