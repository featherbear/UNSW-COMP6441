{

     const passwordInput = document.querySelector('#password');
    const passwordFeedback = document.querySelector('#strength-output');
    const strengthStr = {
        0: 'Worst',
        1: 'Bad',
        2: 'Weak',
        3: 'Good',
        4: 'Strong'
    }
    const canvasWrapper = document.querySelector('.canvas-wrap');
    const canvas = canvasWrapper.querySelector('canvas');

    // The following code was taken and modified from http://jsfiddle.net/u6apxgfk/390/
    // (C) Ken Fyrstenberg, Epistemex, License: CC3.0-attr
    
    // and merged with https://codepen.io/bassta/pen/OPVzyB?editors=1010

    const ctx = canvas.getContext('2d');
    const img = new Image();
    let imgRatio;
    let wrapperRatio;
    let newWidth;
    let newHeight;
    let newX;
    let newY;

    let pxFactor = 100;

    img.src = "img.png";
    img.onload = () => {
        const imgWidth = img.width;
        const imgHeight = img.height;
        imgRatio = imgWidth / imgHeight;
        setCanvasSize();
        render();
    };

    const setCanvasSize = () => {
        canvas.width = canvasWrapper.offsetWidth;
        canvas.height = canvasWrapper.offsetHeight;
    };

    const render = () => {
        const w = canvas.width;
        const h = canvas.height;

        newWidth = w;
        newHeight = h;
        newX = 0;
        newY = 0;
        wrapperRatio = newWidth / newHeight;

        if ( wrapperRatio > imgRatio ) {
            newHeight = Math.round(w / imgRatio);
            newY = (h - newHeight) / 2;
        } 
        else {
            newWidth = Math.round(h * imgRatio);
            newX = (w - newWidth) / 2;
        }

        // pxFactor will depend on the current typed password.
        // values will be in the range [1,100].
        const size = pxFactor * 0.01;

        // turn off image smoothing - this will give the pixelated effect
        ctx.mozImageSmoothingEnabled = size === 1 ? true : false;
        ctx.webkitImageSmoothingEnabled = size === 1 ? true : false;
        ctx.imageSmoothingEnabled = size === 1 ? true : false;

        ctx.clearRect(0, 0, canvas.width, canvas.height);
        // draw original image to the scaled size
        ctx.drawImage(img, 0, 0, w*size, h*size);
        // then draw that scaled image thumb back to fill canvas
        // As smoothing is off the result will be pixelated
        ctx.drawImage(canvas, 0, 0, w*size, h*size, newX, newY, newWidth, newHeight);
    };

    window.addEventListener('resize', () => {
        setCanvasSize();
        render();
    });
    
    const renderResult = (result) => {
        pxFactor = 99/11*Math.min(11,Math.round(result.guesses_log10)) + 1;
        if ( pxFactor != 1 && pxFactor != 100 ) {
            pxFactor -= pxFactor/100*50;
        }
        render();
    } 

    passwordInput.addEventListener('input', () => {
        let val = passwordInput.value;
        let result = zxcvbn(val);
        renderResult(result)
        passwordFeedback.innerHTML = val !== '' ? `Password strength: ${strengthStr[result.score]}` : '';
    });
    
    renderResult(zxcvbn(passwordInput.value || "0"));
}