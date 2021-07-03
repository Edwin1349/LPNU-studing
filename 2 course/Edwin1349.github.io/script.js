function load_data() {
    var mydata = JSON.stringify(performance[0].name);
    console.log(typeof(mydata));
    console.log(mydata);
}

function add_element() {
    for(let i = 0; i < 6; i += 1){
        var mydata = performance[i];
        let div = document.createElement('div');
        div.className = "performance_block";
        div.id = "performance_id_" + i;
    
        div.innerHTML = document.getElementById('blockOfStuff').innerHTML;

        div.querySelector(".author").innerHTML = mydata.author;
        div.querySelector(".performance_name").innerHTML = mydata.performance_name;
        div.querySelector(".time").innerHTML = "початок о " + mydata.time;

        div.querySelector(".day_name").innerHTML = mydata.day_name;
        div.querySelector(".day_num").innerHTML = mydata.day_num;
        div.querySelector(".month_name").innerHTML = mydata.month_name;

        document.getElementsByClassName('content_block')[0].appendChild(div);
        
    }
}

document.body.onload = add_element;

