#Header file
Толгой файл нь идэвчлэн өгөгдлийн төрлйин тодорхойлолт, функцийн прототайп(зарлалт) болон С preprocessor коммандуудыг агуулдаг. 
Толгой файлыг .h өргөтгөлтэйгээр хадгалж бусад файлд оруулахдаа
```
#include "ner.h" //гэж оруулна
```

.Чухал.
Том С програм бичихэд толгой файл үүсгэх нь модулууд хоорондоо функцийн тодорхойлолт, прототайпыг(зарлалтыг) хуваалцхад хэрэг болдог.
- Функц болон төрлийн зарлалт, глобал хувьсагч, бүтцийн зарлалт болон зарим тохиолдолд дотоод мөр функц, болон бусад төвлөрсөн нэг файл байх хэрэгтэй тодорхойлолтууд
- Толгой файлд хэтэрхий их эсвэл бусад толгой файлыг бүү ашигла. Зөвхөн цөөхөн төлвүүдийн олонлог
- функцийн тодорхойлотыг толгой файлд хийх хэрэггүй. Тусад нь .с файлд хий
- Толгой файлд функцийн зарлалт, хувьсагчдын тодорхойлолт мөн өгөгдлийн төрлийн тодорхойлолт enumerations нь олон файлын дунд ашиглагдах ёстой

