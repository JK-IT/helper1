//'https://ebup-bucket.s3-us-west-2.amazonaws.com/' + coimg +'/cover.jpg'
window.onload = function(e){
  var listrows = document.getElementsByClassName('list-row');
  for( var row of listrows){
    row.addEventListener('click', function(e){
      var tar = e.currentTarget;
      tar.classList.add('list-row-active');
      var table = tar.getAttribute('data-tab');
      var key = tar.getAttribute('data-title');
      var blink = 'https://' + table +'.s3-us-west-2.amazonaws.com/'+ key;
      //include pdf script from cdn in html file
      if(PDFObject.supportsPDFs){
        var pdfChild = tar.children[1];
        if(pdfChild.children.length == 0){
          PDFObject.embed(blink, pdfChild,{
          pdfOpenParams:{
            view: 'FitV',
            zoom: 120,
            scrollbar: 1
          }, 
          id: key,
          fallbackLink: "<p>This browser does not support inline PDFs.<br>Option: <b>Open in a pdf supported browser - Google Chrome, FireFox, Explorer Edge </b><br> Or you can download the PDF to view it offline: <a href='[url]'>Download PDF</a></p>" ,
          height: '90vh'
          });
        }
        tar.classList.toggle('list-row-click');
        pdfChild.classList.toggle('pdf-hide');        
      } else {
        //open with 3rd party application
        var a  = `https://docs.google.com/viewerng/viewer?url=${blink}`;
        window.open(a,"_blank");
      }
    })

  }
}

window.onscroll = function(e){
  var banner = document.getElementById('bookBanner');
  var banneroffset = banner.offsetTop + banner.offsetHeight + 10;
  //console.log(banneroffset);
  //console.log(window.pageYOffset);
  var navisc = document.getElementById('naviShortcut');
  if(Math.round(window.scrollY) > banneroffset){
    //console.log('banner disappeared');
    navisc.style.opacity = '1';
  } else if (Math.round(window.scrollY) < (banneroffset - 10)){
    navisc.style.opacity = '0';
  }
}

function GoBack(e){
  var ori = window.location.origin;
  window.history.back();
}

function GoUp(e){
  window.scroll({top: 0, behavior: "smooth"});
}
function GoHome(e){
  window.location.assign(window.location.origin);
}
function GoDown(e){
  var chaplist = document.getElementById('chapList');
  window.scroll({left: 0, top: (chaplist.offsetTop + chaplist.offsetHeight), behavior:"smooth"})
  /* var footer = document.getElementsByTagName('footer');
  footer[0].scrollIntoView(); */
}

