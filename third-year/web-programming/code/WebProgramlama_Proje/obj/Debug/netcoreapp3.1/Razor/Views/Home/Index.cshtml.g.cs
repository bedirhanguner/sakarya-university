#pragma checksum "C:\Users\Lenovo\Desktop\web-programlama\Proje\WebProgramlama_Proje\WebProgramlama_Proje\Views\Home\Index.cshtml" "{ff1816ec-aa5e-4d10-87f7-6f4963833460}" "ccda15976b4af67ab949ea8aafef45a0314c45ef"
// <auto-generated/>
#pragma warning disable 1591
[assembly: global::Microsoft.AspNetCore.Razor.Hosting.RazorCompiledItemAttribute(typeof(AspNetCore.Views_Home_Index), @"mvc.1.0.view", @"/Views/Home/Index.cshtml")]
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
    [global::Microsoft.AspNetCore.Razor.Hosting.RazorSourceChecksumAttribute(@"SHA1", @"ccda15976b4af67ab949ea8aafef45a0314c45ef", @"/Views/Home/Index.cshtml")]
    [global::Microsoft.AspNetCore.Razor.Hosting.RazorSourceChecksumAttribute(@"SHA1", @"dfe2a389c1516d36603cb674a8b5d4d039ad6de4", @"/Views/_ViewImports.cshtml")]
    public class Views_Home_Index : global::Microsoft.AspNetCore.Mvc.Razor.RazorPage<WebProgramlama_Proje.Models.ViewModel>
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
            WriteLiteral("\r\n");
#nullable restore
#line 4 "C:\Users\Lenovo\Desktop\web-programlama\Proje\WebProgramlama_Proje\WebProgramlama_Proje\Views\Home\Index.cshtml"
  
    ViewData["Title"] = "Home Page";

#line default
#line hidden
#nullable disable
            WriteLiteral("\r\n<!DOCTYPE html>\r\n<html>\r\n");
            __tagHelperExecutionContext = __tagHelperScopeManager.Begin("head", global::Microsoft.AspNetCore.Razor.TagHelpers.TagMode.StartTagAndEndTag, "ccda15976b4af67ab949ea8aafef45a0314c45ef3694", async() => {
                WriteLiteral("\r\n    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">\r\n    <link");
                BeginWriteAttribute("href", " href=\"", 213, "\"", 250, 1);
#nullable restore
#line 12 "C:\Users\Lenovo\Desktop\web-programlama\Proje\WebProgramlama_Proje\WebProgramlama_Proje\Views\Home\Index.cshtml"
WriteAttributeValue("", 220, Url.Content("~/css/Home.css"), 220, 30, false);

#line default
#line hidden
#nullable disable
                EndWriteAttribute();
                WriteLiteral(" rel=\"stylesheet\" type=\"text/css\" />\r\n");
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
            __tagHelperExecutionContext = __tagHelperScopeManager.Begin("body", global::Microsoft.AspNetCore.Razor.TagHelpers.TagMode.StartTagAndEndTag, "ccda15976b4af67ab949ea8aafef45a0314c45ef5214", async() => {
                WriteLiteral(@"

    <div class=""about-section"">
        <h1>Musluk</h1>
        <p>WEB Programlama Dersi Proje Ödevi</p>
    </div>
    <br />
    <h2 style=""text-align:center"">Proje Takımı</h2>
    <br /><br />
    <div class=""row"">
        <div class=""column"">
            <div class=""card"">
                <div class=""container"">
                    <h2>Karaay Karaoğul</h2>
                    <p class=""title"">B181210054</p>
                    <p>karaay.karaogul@ogr.sakarya.edu.tr</p>
                    <p><input type=""button"" class=""button"" value=""Github"" onclick=""openKaraay()""></p>
                </div>
            </div>
        </div>

        <div class=""column"">
            <div class=""card"">
                <div class=""container"">
                    <h2>Bedirhan Güner</h2>
                    <p class=""title"">B171210036</p>
                    <p>bedirhan.guner@ogr.sakarya.edu.tr</p>
                    <p><input type=""button"" class=""button"" value=""Github"" onclick=""openBedirhan()""></");
                WriteLiteral(@"p>
                </div>
            </div>
        </div>

        <div class=""column"">
            <div class=""card"">
                <div class=""container"">
                    <h2>Doğukhan Bayram</h2>
                    <p class=""title"">B181210084</p>
                    <p>dogukhan.bayram@ogr.sakarya.edu.tr</p>
                    <p><input type=""button"" class=""button"" value=""Github"" onclick=""openDogukhan()""></p>
                </div>
            </div>
        </div>
    </div>

");
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
            WriteLiteral(@"
</html>

<script>
    function openKaraay() {
        window.open(""https://github.com/karaaykaraogul"");
    }

    function openBedirhan() {
        window.open(""https://github.com/bedirhanguner"");
    }
    function openDogukhan() {
        window.open(""https://github.com/dogukhanbayram"");
    }
</script>");
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
