#pragma checksum "C:\Users\Lenovo\Desktop\web-programlama\Proje\WebProgramlama_Proje\WebProgramlama_Proje\Views\Library\Index.cshtml" "{ff1816ec-aa5e-4d10-87f7-6f4963833460}" "24da7afebcba314cc0a1ff1c91452f6393ffb4ae"
// <auto-generated/>
#pragma warning disable 1591
[assembly: global::Microsoft.AspNetCore.Razor.Hosting.RazorCompiledItemAttribute(typeof(AspNetCore.Views_Library_Index), @"mvc.1.0.view", @"/Views/Library/Index.cshtml")]
namespace AspNetCore
{
    #line hidden
    using System;
    using System.Collections.Generic;
    using System.Linq;
    using System.Threading.Tasks;
    using Microsoft.AspNetCore.Mvc;
    using Microsoft.AspNetCore.Mvc.Rendering;
    using Microsoft.AspNetCore.Mvc.ViewFeatures;
#nullable restore
#line 1 "C:\Users\Lenovo\Desktop\web-programlama\Proje\WebProgramlama_Proje\WebProgramlama_Proje\Views\_ViewImports.cshtml"
using WebProgramlama_Proje;

#line default
#line hidden
#nullable disable
#nullable restore
#line 2 "C:\Users\Lenovo\Desktop\web-programlama\Proje\WebProgramlama_Proje\WebProgramlama_Proje\Views\_ViewImports.cshtml"
using WebProgramlama_Proje.Models;

#line default
#line hidden
#nullable disable
    [global::Microsoft.AspNetCore.Razor.Hosting.RazorSourceChecksumAttribute(@"SHA1", @"24da7afebcba314cc0a1ff1c91452f6393ffb4ae", @"/Views/Library/Index.cshtml")]
    [global::Microsoft.AspNetCore.Razor.Hosting.RazorSourceChecksumAttribute(@"SHA1", @"dfe2a389c1516d36603cb674a8b5d4d039ad6de4", @"/Views/_ViewImports.cshtml")]
    public class Views_Library_Index : global::Microsoft.AspNetCore.Mvc.Razor.RazorPage<WebProgramlama_Proje.Models.ViewModel>
    {
        #line hidden
        #pragma warning disable 0649
        private global::Microsoft.AspNetCore.Razor.Runtime.TagHelpers.TagHelperExecutionContext __tagHelperExecutionContext;
        #pragma warning restore 0649
        private global::Microsoft.AspNetCore.Razor.Runtime.TagHelpers.TagHelperRunner __tagHelperRunner = new global::Microsoft.AspNetCore.Razor.Runtime.TagHelpers.TagHelperRunner();
        #pragma warning disable 0169
        private string __tagHelperStringValueBuffer;
        #pragma warning restore 0169
        private global::Microsoft.AspNetCore.Razor.Runtime.TagHelpers.TagHelperScopeManager __backed__tagHelperScopeManager = null;
        private global::Microsoft.AspNetCore.Razor.Runtime.TagHelpers.TagHelperScopeManager __tagHelperScopeManager
        {
            get
            {
                if (__backed__tagHelperScopeManager == null)
                {
                    __backed__tagHelperScopeManager = new global::Microsoft.AspNetCore.Razor.Runtime.TagHelpers.TagHelperScopeManager(StartTagHelperWritingScope, EndTagHelperWritingScope);
                }
                return __backed__tagHelperScopeManager;
            }
        }
        private global::Microsoft.AspNetCore.Mvc.Razor.TagHelpers.HeadTagHelper __Microsoft_AspNetCore_Mvc_Razor_TagHelpers_HeadTagHelper;
        private global::Microsoft.AspNetCore.Mvc.Razor.TagHelpers.BodyTagHelper __Microsoft_AspNetCore_Mvc_Razor_TagHelpers_BodyTagHelper;
        #pragma warning disable 1998
        public async override global::System.Threading.Tasks.Task ExecuteAsync()
        {
            WriteLiteral("\r\n");
#nullable restore
#line 3 "C:\Users\Lenovo\Desktop\web-programlama\Proje\WebProgramlama_Proje\WebProgramlama_Proje\Views\Library\Index.cshtml"
  
    ViewData["Title"] = "Library";
    int currentUser = 0;

#line default
#line hidden
#nullable disable
            WriteLiteral("\r\n<!DOCTYPE html>\r\n\r\n<html>\r\n");
            __tagHelperExecutionContext = __tagHelperScopeManager.Begin("head", global::Microsoft.AspNetCore.Razor.TagHelpers.TagMode.StartTagAndEndTag, "24da7afebcba314cc0a1ff1c91452f6393ffb4ae3705", async() => {
                WriteLiteral("\r\n    <link");
                BeginWriteAttribute("href", " href=\"", 163, "\"", 208, 1);
#nullable restore
#line 12 "C:\Users\Lenovo\Desktop\web-programlama\Proje\WebProgramlama_Proje\WebProgramlama_Proje\Views\Library\Index.cshtml"
WriteAttributeValue("", 170, Url.Content("~/css/LibraryIndex.css"), 170, 38, false);

#line default
#line hidden
#nullable disable
                EndWriteAttribute();
                WriteLiteral(" rel=\"stylesheet\" type=\"text/css\" />\r\n\r\n    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">\r\n");
            }
            );
            __Microsoft_AspNetCore_Mvc_Razor_TagHelpers_HeadTagHelper = CreateTagHelper<global::Microsoft.AspNetCore.Mvc.Razor.TagHelpers.HeadTagHelper>();
            __tagHelperExecutionContext.Add(__Microsoft_AspNetCore_Mvc_Razor_TagHelpers_HeadTagHelper);
            await __tagHelperRunner.RunAsync(__tagHelperExecutionContext);
            if (!__tagHelperExecutionContext.Output.IsContentModified)
            {
                await __tagHelperExecutionContext.SetOutputContentAsync();
            }
            Write(__tagHelperExecutionContext.Output);
            __tagHelperExecutionContext = __tagHelperScopeManager.End();
            WriteLiteral("\r\n");
            __tagHelperExecutionContext = __tagHelperScopeManager.Begin("body", global::Microsoft.AspNetCore.Razor.TagHelpers.TagMode.StartTagAndEndTag, "24da7afebcba314cc0a1ff1c91452f6393ffb4ae5240", async() => {
                WriteLiteral("\r\n");
#nullable restore
#line 17 "C:\Users\Lenovo\Desktop\web-programlama\Proje\WebProgramlama_Proje\WebProgramlama_Proje\Views\Library\Index.cshtml"
     foreach (var item in Model.Users)
    {
        if (item.userMail == User.Identity.Name)
        {
            currentUser = item.userID;
        }
    }

#line default
#line hidden
#nullable disable
                WriteLiteral("\r\n");
#nullable restore
#line 25 "C:\Users\Lenovo\Desktop\web-programlama\Proje\WebProgramlama_Proje\WebProgramlama_Proje\Views\Library\Index.cshtml"
     foreach (var oyun in Model.Games)
    {
        

#line default
#line hidden
#nullable disable
#nullable restore
#line 27 "C:\Users\Lenovo\Desktop\web-programlama\Proje\WebProgramlama_Proje\WebProgramlama_Proje\Views\Library\Index.cshtml"
         foreach (var lib in Model.Libraries)
        {

            

#line default
#line hidden
#nullable disable
#nullable restore
#line 30 "C:\Users\Lenovo\Desktop\web-programlama\Proje\WebProgramlama_Proje\WebProgramlama_Proje\Views\Library\Index.cshtml"
             if (lib.userID == currentUser)
            {
                

#line default
#line hidden
#nullable disable
#nullable restore
#line 32 "C:\Users\Lenovo\Desktop\web-programlama\Proje\WebProgramlama_Proje\WebProgramlama_Proje\Views\Library\Index.cshtml"
                 if (lib.gameID == oyun.gameID)
                {

#line default
#line hidden
#nullable disable
                WriteLiteral("                    <table class=\"TableSelf\">\r\n                        <tr>\r\n                            <td class=\" TableText\">\r\n                                <img");
                BeginWriteAttribute("src", " src=", 909, "", 927, 1);
#nullable restore
#line 37 "C:\Users\Lenovo\Desktop\web-programlama\Proje\WebProgramlama_Proje\WebProgramlama_Proje\Views\Library\Index.cshtml"
WriteAttributeValue("", 914, oyun.gameIMG, 914, 13, false);

#line default
#line hidden
#nullable disable
                EndWriteAttribute();
                WriteLiteral(" class=\" TableImage\" />\r\n                            </td>\r\n\r\n                            <td class=\" TableTextMiddle\">\r\n                                <a>");
#nullable restore
#line 41 "C:\Users\Lenovo\Desktop\web-programlama\Proje\WebProgramlama_Proje\WebProgramlama_Proje\Views\Library\Index.cshtml"
                              Write(oyun.gameName);

#line default
#line hidden
#nullable disable
                WriteLiteral(" </a>\r\n                            </td>\r\n                            <td class=\" TableTextRight\">\r\n                                <a>");
#nullable restore
#line 44 "C:\Users\Lenovo\Desktop\web-programlama\Proje\WebProgramlama_Proje\WebProgramlama_Proje\Views\Library\Index.cshtml"
                              Write(oyun.gamePrice);

#line default
#line hidden
#nullable disable
                WriteLiteral(" </a>\r\n                            </td>\r\n                        </tr>\r\n\r\n                    </table>\r\n                    <br />\r\n");
#nullable restore
#line 50 "C:\Users\Lenovo\Desktop\web-programlama\Proje\WebProgramlama_Proje\WebProgramlama_Proje\Views\Library\Index.cshtml"
                }

#line default
#line hidden
#nullable disable
#nullable restore
#line 50 "C:\Users\Lenovo\Desktop\web-programlama\Proje\WebProgramlama_Proje\WebProgramlama_Proje\Views\Library\Index.cshtml"
                 
            }

#line default
#line hidden
#nullable disable
#nullable restore
#line 51 "C:\Users\Lenovo\Desktop\web-programlama\Proje\WebProgramlama_Proje\WebProgramlama_Proje\Views\Library\Index.cshtml"
             
        }

#line default
#line hidden
#nullable disable
#nullable restore
#line 52 "C:\Users\Lenovo\Desktop\web-programlama\Proje\WebProgramlama_Proje\WebProgramlama_Proje\Views\Library\Index.cshtml"
         
    }

#line default
#line hidden
#nullable disable
            }
            );
            __Microsoft_AspNetCore_Mvc_Razor_TagHelpers_BodyTagHelper = CreateTagHelper<global::Microsoft.AspNetCore.Mvc.Razor.TagHelpers.BodyTagHelper>();
            __tagHelperExecutionContext.Add(__Microsoft_AspNetCore_Mvc_Razor_TagHelpers_BodyTagHelper);
            await __tagHelperRunner.RunAsync(__tagHelperExecutionContext);
            if (!__tagHelperExecutionContext.Output.IsContentModified)
            {
                await __tagHelperExecutionContext.SetOutputContentAsync();
            }
            Write(__tagHelperExecutionContext.Output);
            __tagHelperExecutionContext = __tagHelperScopeManager.End();
            WriteLiteral("\r\n</html>\r\n");
        }
        #pragma warning restore 1998
        [global::Microsoft.AspNetCore.Mvc.Razor.Internal.RazorInjectAttribute]
        public global::Microsoft.AspNetCore.Mvc.ViewFeatures.IModelExpressionProvider ModelExpressionProvider { get; private set; }
        [global::Microsoft.AspNetCore.Mvc.Razor.Internal.RazorInjectAttribute]
        public global::Microsoft.AspNetCore.Mvc.IUrlHelper Url { get; private set; }
        [global::Microsoft.AspNetCore.Mvc.Razor.Internal.RazorInjectAttribute]
        public global::Microsoft.AspNetCore.Mvc.IViewComponentHelper Component { get; private set; }
        [global::Microsoft.AspNetCore.Mvc.Razor.Internal.RazorInjectAttribute]
        public global::Microsoft.AspNetCore.Mvc.Rendering.IJsonHelper Json { get; private set; }
        [global::Microsoft.AspNetCore.Mvc.Razor.Internal.RazorInjectAttribute]
        public global::Microsoft.AspNetCore.Mvc.Rendering.IHtmlHelper<WebProgramlama_Proje.Models.ViewModel> Html { get; private set; }
    }
}
#pragma warning restore 1591
