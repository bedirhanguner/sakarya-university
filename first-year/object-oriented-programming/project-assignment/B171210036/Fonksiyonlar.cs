using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace B171210036_1D_PROJE
{
    interface IFonksiyonlar
    {
        int CanAzalt();
        int CanTazele();
        int CanAzalmaMiktari { get; set;}
        int UretimSikligi { get; set;}
    }
}
